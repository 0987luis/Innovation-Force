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
 * Our robot is completely custom designed, that's why we decided to use a robotics kit where we connect the servo motor with the steering, or 
   rather we screw it with the wheels as if they were the steering of a remote control car, but better and even better, it has not given us 
   problems, it is very effective in turning, precise and efficient, which helped us perfectly do the three turns super fast.


* To ensure efficient power supply for our Robotics project, we have implemented a power system with two separate batteries. One of the batteries 
  is dedicated exclusively to powering the Arduino, ensuring a stable and interference-free power supply. The second battery is responsible for 
  powering both the motor controller (drive) and the servo motor, optimizing power distribution and ensuring that both components operate 
  efficiently and without interruptions. This configuration guarantees optimal performance in the development of the project. It is worth 
  mentioning that the power is 100/100 effective.
