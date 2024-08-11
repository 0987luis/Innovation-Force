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

  
