![Carro actual](fotos_/carro%20actual%20desde%2027%20de%20junio.jpg)





Team members
* HECTOR GONZALES 
* LUIS ESPINOSA


* Overview of our repository
* schemes- contains the circuit diagram, wiring diagram and driving diagram.
* src - the codes for both challenges, with and without obstacles.
* t-photos - photos of the team and a funny one.
* v-photos - photos of every angle of the robot.

  COMPONEST
* Breadboard
* Arduino Uno
* L298N Driver
* 7.4V Polymer Batteries
*Traction Motor
* MG996R Servo
* Ultrasonic Sensors (x3)
* Potentiometers
* Push Buttons (x2)
* Male-Male and Male-Female Cables
* Robotic Car Kit
* Raspberry Pi
* Webcam
* Portable Battery
  
Strategy

* Robot movement strategy: Our mobility system for the robot is driven by a single motor (see component list), which connects our two wheels through a gear, to interlock the action of the motor, that is, so that the two rear wheels have traction, to see what the rear traction of the vehicle is like you can see the photos of the robot or the part of the model.

Steering

The steering is handled by a servo motor, which is connected to the wheels in an ingenious way, since the servo motor works like a gear, so that when it moves it moves in the form of an arc or curve, so that the mobility of the steering and when taking curves is quite exact also when calibrating the directions are precise. Our steering is simple but at the same time complex, but above all ingenious and quite precise.


-Camera/Object Detection: 

* -Camera/Object Detection: For the second round, we are using a webcam, which is a useful camera but not as fast as we thought for what we needed, but it was the one 
  we could get but it is still essential for its function while we were practicing we were realizing that it was a bit slow and that made color detection a bit more 
  complicated.

  For the first round:

* it was a little difficult because we had the programming well if not, sometimes the servo gave us a few problems but after that in the code we put a bool variable 
  that adds up every time the evade left or right function is executed and reaches twelve and the car stops if it detects and if it has a distance of 80 or 84 it will 
  continue but it will still stop perfectly.

  
Mobility strategy
 * Our robot has been custom designed, which led us to opt for a specific robotics kit for its construction. Instead of following a standard design, we decided to integrate a servo motor that connects to the robot's steering. To achieve this, we screwed the servo motor to the wheels, thus emulating the steering system of a remote-controlled car. This approach has not only proven to be more effective, but has also exceeded our expectations in terms of performance. The robot's steering system has proven to be exceptionally reliable, with no issues to date. Its ability to perform turns is precise and efficient, allowing us to execute three consecutive turns extremely quickly and with great precision. This effectiveness in turning has been key to achieving our goals in the design of the robot.


* To ensure efficient power supply for our Robotics project, we have implemented a power system with two separate batteries. One of the batteries 
  is dedicated exclusively to powering the Arduino, ensuring a stable and interference-free power supply. The second battery is responsible for 
  powering both the motor controller (drive) and the servo motor, optimizing power distribution and ensuring that both components operate 
  efficiently and without interruptions. This configuration guarantees optimal performance in the development of the project. It is worth 
  mentioning that the power is 100/100 effective.

* But before all of this we had certain challenges, our second challenge was that of our two servos we didn't know why they burned out, it was too much voltage, it could be that we tested too much, we spent a whole day programming and that was one of our problems and every time a servo burned out we had to wait 10 days or more for a new servo and we also added a voltmeter to measure the voltages and we avoided this from happening to us.

* Our first challenge was the track. We had no track for a while until a school lent us the track and that was where we got serious about working. But before they lent us that track, we made a homemade track with the exact measurements. Although it wasn't easy with that track, we had to do everything. We couldn't just sit back and do nothing.

* Another challenge that wasn't so difficult, but it was something that saved us time, was the Let screen. Before we had that screen, we had to be connected to the cart to take the measurements of left, right, back and forth. But with the screen, everything was easier. It even made it easy for us so that the cart could make its correct and perfect turns.

* Another somewhat strange challenge when we had the track and started programming was that the car drifted too much and couldn't make the turns well. It slid and crashed. For that, we had to slow down, but it made the turns very slowly. Almost every turn was like a minute and thirty minutes. We couldn't wait that long and what we came up with was putting rubber on the tires and that was the solution to that problem.


Estrategia

* Estrategia de movimiento del robot: Nuestro sistema de movilidad para el robot es impulsado por un solo motor (ver lista de componentes), el cual conecta nuestras dos ruedas a través de un engrane, para engranar la acción del motor, es decir, para que las dos ruedas traseras tengan tracción, para ver como es la tracción trasera del vehículo puedes ver las fotos del robot o la parte del modelo.

Dirección

La dirección es manejada por un servomotor, el cual está conectado a las ruedas de una manera ingeniosa, ya que el servomotor funciona como un engrane, de manera que al moverse se mueve en forma de arco o curva, de manera que la movilidad de la dirección y al tomar curvas es bastante exacta también al calibrar las direcciones son precisas. Nuestra dirección es sencilla pero a la vez compleja, pero sobre todo ingeniosa y bastante precisa.

-Cámara/Detección de objetos:

* -Cámara/Detección de objetos: Para la segunda ronda, estamos usando una webcam, que es una cámara útil pero no tan rápida como pensábamos para lo que necesitábamos, pero era la
que podíamos conseguir pero igual es imprescindible para su función mientras íbamos practicando nos íbamos dando cuenta de que era un poco lenta y eso hacía un poco más
complicada la detección de colores.

Para la primera ronda:

* fue un poco difícil porque teníamos la programación bien si no, a veces el servo nos daba unos cuantos problemas pero después de eso en el código pusimos una variable bool
que se suma cada vez que se ejecuta la función evade left o right y llega a doce y el coche se detiene si detecta y si tiene una distancia de 80 o 84 seguirá
pero seguirá parando perfectamente.

Estrategia de movilidad
* Nuestro robot ha sido diseñado a medida, lo que nos llevó a optar por un kit de robótica específico para su construcción. En lugar de seguir un diseño estándar, decidimos integrar un servomotor que se conecta a la dirección del robot. Para lograrlo, atornillamos el servomotor a las ruedas, emulando así el sistema de dirección de un coche teledirigido. Este enfoque no solo ha demostrado ser más efectivo, sino que también ha superado nuestras expectativas en términos de rendimiento. El sistema de dirección del robot ha demostrado ser excepcionalmente confiable, sin problemas hasta la fecha. Su capacidad para realizar giros es precisa y eficiente, lo que nos permite ejecutar tres giros consecutivos de manera extremadamente rápida y con gran precisión. Esta efectividad en el giro ha sido clave para lograr nuestros objetivos en el diseño del robot.

* Para asegurar un suministro de energía eficiente para nuestro proyecto de Robótica, hemos implementado un sistema de alimentación con dos baterías separadas. Una de las baterías
está dedicada exclusivamente a alimentar el Arduino, asegurando un suministro de energía estable y sin interferencias. La segunda batería se encarga de
alimentar tanto el controlador del motor (drive) como el servomotor, optimizando la distribución de energía y asegurando que ambos componentes funcionen
de manera eficiente y sin interrupciones. Esta configuración garantiza un rendimiento óptimo en el desarrollo del proyecto. Cabe
mencionar que la alimentación es 100/100 efectiva.

* Pero antes de todo esto teníamos ciertos retos, nuestro segundo reto fue que de nuestros dos servos no sabíamos por qué se quemaban, era demasiado voltaje, podía ser que probamos demasiado, pasamos un día entero programando y ese era uno de nuestros problemas y cada vez que se quemaba un servo teníamos que esperar 10 días o más por un servo nuevo y además agregamos un voltímetro para medir los voltajes y evitamos que esto nos pasara.

* Nuestro primer reto fue la pista. No tuvimos pista por un tiempo hasta que una escuela nos prestó la pista y ahí fue donde nos pusimos serios a trabajar. Pero antes de que nos prestaran esa pista, hicimos una pista casera con las medidas exactas. Aunque no era fácil con esa pista, teníamos que hacer todo. No podíamos quedarnos sentados sin hacer nada.

* Otro reto que no fue tan difícil, pero fue algo que nos ahorró tiempo, fue la pantalla Let. Antes de tener esa pantalla, teníamos que estar conectados al carrito para tomar las medidas de izquierda, derecha, adelante y atrás. Pero con la pantalla todo fue más fácil. Incluso nos facilitó las cosas para que el carro pudiera hacer sus giros correctos y perfectos.

*Otro reto un poco extraño cuando teníamos la pista y empezamos a programar era que el carro derrapaba demasiado y no podía hacer bien los giros. Se deslizaba y chocaba. Para eso teníamos que bajar la velocidad, pero hacía los giros muy lento. Casi cada giro era como de minuto y treinta minutos. No podíamos esperar tanto y lo que se nos ocurrió fue ponerle goma a las llantas y esa fue la solución a ese problema.

  