# Line-Follower
Autonomous Line follower, started as a part of [SDP 2.0](https://www.niser.ac.in/~smishra/club/rtc/skill-development-program/) in attempt for competitions.  
***1st Runners-up*** in Line Follower, [NIRMAN 2.0](https://www.nirmansilicon.tech/), Silicon Institute, Bhubaneswar. 
# Components & Materials
- Arduino Uno & Connector
- Two parallel lines of bread-board, Jumpers, Switch-SPST
- Li-ion battery 3S: ~12V(_preferred_)  or Alkaline battery: 9V
- IR Sensors x5
- L298N (2C) Motor Driver
- DC Motors x2
- Chassis, Motor Wheels x2, Castor x1
- Nuts & Bolts, Glue gun, Soldering iron, Double Tapes
# Working Idea
# Code (Arduino)
Written on Arduino. There are two version: 
- Casewise/Conditional high-lows (_Used in NIRMAN-2.0_)
- PID (_Used in Wissenaire-23_)
# Circuit
Generic Design for motors with 5 sensors to arduino.
### Wirings
# Chassis 
### Design
- 17cm (height) X 14cm (width) body.
- Front panel to stick IR sensors
- Cover panel to sandwich and hold the motors.

Since the cut was made on 5mm acrylic, the front panel was not required in the final setup. _Note_ that using the front panel keeps all the sensors one line. _Otherwise_ it stays in an inverted V shape which can give some strategical advantage (like detecting crosses better).
### Irregularities/Errors 
The top screw holes might be a bit off. 
# Members
Aditya Kamble (Captain) - Chassis Design, Co-ordination  
Vishal Meena - Code, Algorithm  
Aayush Jelmeria - Co-ordination, Track Design  
Karan K. Sahoo - Chassis Design, Algorithm  
Sanat k. Behera - Chassis Design, Circuit  
S. Mahesh (Mentor) - Code, Algorithm, Working Idea  
[Girija S. Ray](https://github.com/Alpha3125) (Mentor) - Code, Track Design, Circuit  
