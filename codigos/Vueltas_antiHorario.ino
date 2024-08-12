// Incluir Bibliotecas Necesarias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
// Parte de las Bibliotecas
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
Servo servoMotor;

// Configuración de los sensores ultrasónicos
const int TriggerFrente = 2;
const int EchoFrente = 3;
const int TriggerIzquierda = 4;
const int EchoIzquierda = 5;
const int TriggerDerecha = 6;
const int EchoDerecha = 7;

// Pines del driver del motor
const int motorPin1 = 9;
const int motorPin2 = 10;
const int motorVelocidad = 11;

// Pines para el boton
const int pinIzqGiro = 8; // Botón para activar el sistema

// Velocidad del vehículo
const int velocidadNormal =166; // Velocidad normal para todo el vehículo

// Variables para almacenar distancias
long distanciaFrente, distanciaIzquierda, distanciaDerecha, distanciaAtras;

// Intervalos para la actualización de sensores y pantalla
unsigned long ultimoTiempoActualizacion = 0;
const unsigned long intervaloActualizacion = 80; // Reducido a 80 ms para más frecuencia

// Distancias mínimas permitidas para el centrado
const int distanciaMinimaIzquierda = 31;   // Distancia mínima permitida a la izquierda
const int distanciaMinimaDerecha = 31;     // Distancia mínima permitida a la derecha

// Variable para controlar el tiempo después de evadir obstáculos
unsigned long tiempoUltimaEvasion = 0;
const unsigned long intervaloEsperarDespuesEvasion = 100; // Esperar 100 ms después de evadir obstáculos

bool sistemaActivado = false; // Estado del sistema
bool inicioEjecutado = false; // Variable para controlar si inicio() ya se ejecutó una vez

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();

  // Configuración de los pines de los sensores
  pinMode(TriggerFrente, OUTPUT);
  pinMode(EchoFrente, INPUT);
  pinMode(TriggerIzquierda, OUTPUT);
  pinMode(EchoIzquierda, INPUT);
  pinMode(TriggerDerecha, OUTPUT);
  pinMode(EchoDerecha, INPUT);

  // Configuración de los pines del motor
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorVelocidad, OUTPUT);

  // Configuración del servo motor
  servoMotor.attach(12); // Pin del servo motor
  controlServo(142); // Centrar el servo motor al inicio

  // Configuración del botón para activar el sistema
  pinMode(pinIzqGiro, INPUT_PULLUP); // Pin 8 como entrada con resistencia pull-up

  // No encender el motor al inicio
  moverVehiculo(0); // Detener el vehículo al inicio
}

// Función para medir distancia
long getDistancia(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long duracion = pulseIn(echoPin, HIGH, 20000); // Timeout de 20 ms
  if (duracion == 0) return 500; // Si no hay respuesta, asumir distancia máxima (500 cm)
  
  long distancia = duracion * 0.034 / 2;
  return distancia;
}

// Función para controlar el servo
void controlServo(int angulo) {
  servoMotor.write(angulo);
}

// Función para mover el vehículo
void moverVehiculo(int direccion) {
  analogWrite(motorVelocidad, velocidadNormal); // Establecer la velocidad normal
  if (direccion == 1) { // Adelante
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  } else if (direccion == -1) { // Atrás
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  } else { // Detener
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
}

// Función para actualizar la pantalla LCD
void actualizarLCD() {
  lcd.setCursor(0, 0);
  lcd.print("F:");
  lcd.print(distanciaFrente);
  lcd.print("cm B:");
  lcd.print(distanciaAtras);
  lcd.print("cm    ");  // Añadir espacios para borrar caracteres adicionales

  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(distanciaIzquierda);
  lcd.print("cm R:");
  lcd.print(distanciaDerecha);
  lcd.print("cm    ");  // Añadir espacios para borrar caracteres adicionales
}

// Función para actualizar las distancias
void actualizarDistancias() {
  distanciaFrente = getDistancia(TriggerFrente, EchoFrente);
  distanciaIzquierda = getDistancia(TriggerIzquierda, EchoIzquierda);
  distanciaDerecha = getDistancia(TriggerDerecha, EchoDerecha);
}

// Función para evadir obstáculos hacia la izquierda
void evadirIzq() {
  if (distanciaFrente < 84) { // si distancia frontal es menor que 84 Gire
    moverVehiculo(1); // Avanzar durante la evasión
    unsigned long tiempoInicio = millis();
    while (millis() - tiempoInicio < 1250) { // Evasión de obstáculos por 1.2 segundos
      controlServo(109); // Dirección hacia la izquierda
      delay(10); // Reducido para lecturas rápidas de los sensores
      actualizarDistancias(); // Actualizar distancias durante la evasión
    }
    controlServo(141); // Volver al centro al finalizar la evasión
    tiempoUltimaEvasion = millis(); // Registrar el tiempo de la última evasión
  }
}

// Función para acomodar el vehículo después de la evasión esto srive para que no se acerque a las paredes
void acomodar() {
  // Verificar si ha pasado suficiente tiempo desde la última evasión
  if (millis() - tiempoUltimaEvasion < intervaloEsperarDespuesEvasion) {
    return; // Si no ha pasado suficiente tiempo, salir de la función
  }
  if (distanciaFrente < 105){
    return;
  }
  // Ajustar la posición del vehículo para mantenerlo en el centro del espacio
  if (distanciaIzquierda < distanciaMinimaIzquierda) {
    controlServo(156); // Girar hacia la derecha
    delay(300); // Gi8rar por 300 ms en dirección contraria
    controlServo(134); // Girar un poco hacia la dirección de la pared
    delay(200); // Esperar 200 ms
    controlServo(141); // Regresar al centro
    delay(50); // Esperar para permitir que el servo regrese al centro
  } else if (distanciaDerecha < distanciaMinimaDerecha) {
    controlServo(125); // Girar hacia la izquierda
    delay(300); // Girar por 300 ms en dirección contraria
    controlServo(150); // Girar un poco hacia la dirección de la pared
    delay(200); // Esperar 200 ms
    controlServo(141); // Regresar al centro
    delay(50); // Esperar para permitir que el servo regrese al centro
  }
}

// Función para verificar las condiciones de inicio
void inicio() {
  long distanciaFrontal = getDistancia(TriggerFrente, EchoFrente);
  long distanciaDer = getDistancia(TriggerDerecha, EchoDerecha);
  long distanciaIz = getDistancia(TriggerIzquierda, EchoIzquierda);

 // sirve para que se acerque lo mas posible a la pared de frente y agarrar velocidad 
  if (distanciaFrontal >= 146 && distanciaFrontal <= 171 && distanciaIz >= 43 && distanciaIz <= 50) {
    controlServo(139);
    moverVehiculo(1); 
    delay(2000);
  
  }

}

void loop() {
 unsigned long tiempoActual = millis();

  // Actualizar distancias y pantalla LCD
  if (tiempoActual - ultimoTiempoActualizacion >= intervaloActualizacion) {
    actualizarDistancias(); // Actualizar las distancias
    actualizarLCD(); // Actualizar la pantalla LCD
    ultimoTiempoActualizacion = tiempoActual; // Actualizar el tiempo de la última actualización
  }

  // Leer estado del botón IzqGiro para activar el sistema
  if (!sistemaActivado && digitalRead(pinIzqGiro) == LOW) {
    sistemaActivado = true;
    if (!inicioEjecutado) {
      inicio();
      inicioEjecutado = true; // Marcar que inicio() ya se ejecutó una vez
    }
    moverVehiculo(1); // Encender el vehículo al activar el sistema
    evadirIzq(); // Iniciar evasión hacia la izquierda al activar el sistema
    acomodar(); // Acomodar el vehículo después de evadir obstáculos 
  }

  // Ejecutar lógica del sistema si está activado
  if (sistemaActivado) {
    // Lógica del sistema aquí
    evadirIzq(); // Evasión de obstáculos continua hacia la izquierda (bloqueado después del primer uso)
    acomodar(); // Acomodar el vehículo después de evadir obstáculos 
  }

  // Mantener un pequeño delay para mejorar la frecuencia de iteración
  delay(50);
}