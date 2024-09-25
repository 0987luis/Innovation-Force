#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Servo.h>
#define BotonIzquierda 13   // Botón para iniciar el programa y seleccionar giro a la izquierda (I)
#define BotonDerecha 12  // Botón para iniciar el programa y seleccionar giro a la derecha (D)

// Crear el objeto del shield del motor con la dirección I2C predeterminada 
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor = AFMS.getMotor(2); // Para controlar el motor conectado al puerto M2
Adafruit_MS_PWMServoDriver pwm = Adafruit_MS_PWMServoDriver();

// Pines de los sensores ultrasónicos
const int trigFrontal = 6;
const int echoFrontal = 7;
const int trigIzq = 9;
const int echoIzq = 8;
const int trigDer = 4;
const int echoDer = 5;

// Configuración de servo
Servo myServo;

int pos = 140;  // Posición inicial del servo
int bandera = 0;  // Estado del sistema (activado o no)
char direccionGiro = ' ';  // Almacenar la dirección del giro seleccionada (I o D)
int contadorGiros = 0;  // Contador de giros

// Variables para almacenar distancias
long distanciaFrontal, distanciaIzquierda, distanciaDerecha;
const int distanciaMinimaIzquierda = 30;  // Distancia mínima aceptable a la izquierda
const int distanciaMinimaDerecha = 30;    // Distancia mínima aceptable a la derecha

// Distancia límite para girar
const int distanciaLimiteFrontal = 108;  
const int distanciaLimiteAcomodar = 112; 

void setup() {
  Serial.begin(9600);
  // Configuración de los botones
  pinMode(BotonIzquierda, INPUT_PULLUP);  // Botón para seleccionar el giro a la  izquierda
  pinMode(BotonDerecha, INPUT_PULLUP);  // Botón para seleccionar el giro a la derecha

  // Llamar a la función que inicializa todos los componentes
  IniciarComponentes();

  Serial.println("Sistema listo.");
}

void loop() {
  byte arranqueIzq = digitalRead(BotonIzquierda);
  byte arranqueDer = digitalRead(BotonDerecha);

  // Encender el sistema al presionar uno de los botones una vez
  if (bandera == 0) {
    if (arranqueIzq == LOW) {
      direccionGiro = 'I';  // Seleccionar giro a la izquierda
      bandera = 1;  // Activar el sistema
      Serial.println("Sistema encendido, girando a la izquierda cuando sea necesario.");
      moverAdelante(195);  // Iniciar movimiento
    } else if (arranqueDer == LOW) {
      direccionGiro = 'D';  // Seleccionar giro a la derecha
      bandera = 1;  // Activar el sistema
      Serial.println("Sistema encendido, girando a la derecha cuando sea necesario.");
      moverAdelante(195);  // Iniciar movimiento
    }
  }

  // Ejecutar el programa cuando el sistema esté activado
  if (bandera == 1) {
    // Actualizar las distancias de los sensores
    actualizarDistancias();

    // Llamar a la función acomodar
    acomodar();

    if (distanciaFrontal <= distanciaLimiteFrontal) {
      Serial.println("Obstáculo detectado a menos de 105 cm.");
      realizarGiro(direccionGiro);  // Realizar giro automático según el botón seleccionado

      // Detener el carro después de 12 giros
      if (contadorGiros >= 12) {
        Serial.println("12 giros completados, deteniendo el sistema.");
        moverAtras();
        delay(500);
        Detener();
        bandera = 0;  // Desactivar el sistema
      }
    } else {
      moverAdelante(188);  // Seguir avanzando 
    }
  }

  delay(50);  // Pausa para evitar saturar el sistema
}

void realizarGiro(char direccion) {
  // Ajustar el servo para iniciar el giro
  int servoPos;
  if (direccion == 'D') {
    servoPos = 166;  // Girar a la derecha
    Serial.println("Girando a la derecha...");
  } else if (direccion == 'I') {
    servoPos = 118;  // Girar a la izquierda
    Serial.println("Girando a la izquierda...");
  } else {
    return;  // Si la dirección no es ni 'D' ni 'I', no hacer nada
  }

  myServo.write(servoPos);  // Ajustar el servo para girar

  // Mantener el giro durante 1.3 segundos
  unsigned long tiempoInicio = millis();
  while (millis() - tiempoInicio < 1150) {
    // Pausa durante el giro
  }

  // Incrementar el contador de giros
  contadorGiros++;

  // Terminar el giro y regresar el servo a la posición inicial
  myServo.write(138);  

  // Después del giro, avanzar por 60 para evitar fallas 
  moverAdelante(195);
  delay(60);  // Pausa de 60 ms para avanzar antes de volver a medir las distancias
  Serial.println("Giro completado, regresando a la posición recta y avanzando.");
}

void IniciarComponentes() {
  AFMS.begin();  // Inicializar el motor shield
  myMotor->setSpeed(195);
  myMotor->run(RELEASE);

  myServo.attach(10); // Conectar el servo al pin 10
  myServo.write(140); // Posición inicial

  pinMode(trigFrontal, OUTPUT);
  pinMode(echoFrontal, INPUT);
  pinMode(trigIzq, OUTPUT);
  pinMode(echoIzq, INPUT);
  pinMode(trigDer, OUTPUT);
  pinMode(echoDer, INPUT);
}

// Función para medir distancia
long getDistancia(int trigger, int echo) {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  long duracion = pulseIn(echo, HIGH, 20000); // Timeout de 20 ms
  if (duracion == 0) return 500; // Si no hay respuesta, asumir distancia máxima (500 cm)
  
  long distancia = duracion * 0.034 / 2;
  return distancia;
}

// Función para actualizar las distancias de los sensores
void actualizarDistancias() {
  distanciaFrontal = getDistancia(trigFrontal, echoFrontal);
  distanciaIzquierda = getDistancia(trigIzq, echoIzq);
  distanciaDerecha = getDistancia(trigDer, echoDer);

  // Mostrar distancias en el monitor serial para verificar
  Serial.print("Distancia Frontal: ");
  Serial.print(distanciaFrontal);
  Serial.print(" cm, Izquierda: ");
  Serial.print(distanciaIzquierda);
  Serial.print(" cm, Derecha: ");
  Serial.println(distanciaDerecha);
}

void Detener() { // Detener El motor
  myMotor->setSpeed(0);
  myMotor->run(RELEASE);
  myServo.write(140);
  Serial.println("Vehículo detenido.");
}

void moverAdelante(int velocidad) { // mover para adelante
  myMotor->setSpeed(velocidad);
  myMotor->run(FORWARD);
}

void moverAtras(int velocidad = 195) { // mover para atras
  myMotor->setSpeed(velocidad);
  myMotor->run(BACKWARD); 
}

// Función para ajustar la posición del vehículo
void acomodar() {
  if (distanciaFrontal < distanciaLimiteAcomodar){
    return;
  }
  // Ajustar la posición del vehículo para mantenerlo en el centro del espacio
  if (distanciaIzquierda < distanciaMinimaIzquierda) {
    myServo.write(154); // Girar hacia la derecha
    delay(150); // Girar por 150
    myServo.write(133); // Girar un poco hacia la dirección de la pared
    delay(100); // Esperar 100 ms
    myServo.write(140); // Regresar al centro
    delay(20); // Esperar para permitir que el servo regrese al centro
  } else if (distanciaDerecha < distanciaMinimaDerecha) {
    myServo.write(127); // Girar hacia la izquierda
    delay(150); // Girar por 150 ms
    myServo.write(147); // Girar un poco hacia la dirección de la pared
    delay(120); // Esperar 100 ms
    myServo.write(140); // Regresar al centro
    delay(20); // Esperar para permitir que el servo regrese al centro
  }
}
