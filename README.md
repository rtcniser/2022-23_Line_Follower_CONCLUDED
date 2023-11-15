# Line-Follower
Autonomous Line follower, started as a part of [SDP 2.0](https://www.niser.ac.in/~smishra/club/rtc/skill-development-program/) in an attempt for competitions.  
***1st Runners-up*** in Line Follower, [NIRMAN 2.0](https://www.nirmansilicon.tech/), Silicon Institute, Bhubaneswar.  
***Winners*** in Trekkon(Line follower), [WISSENAIRE-23](https://www.wissenaire.org/), Indian Institute of Technology, Bhubaneswar. 
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
Line Follower Robot (LFR) is a simple autonomously guided robot that follows a
dark line on a white surface. The robot detects the line with the help of an IR
sensor. The IR has a transmitter and a receiver. The transmitter emits the infrared
light which is received by the receiver after the reflection from the surface. We all
know that the reflection of light on the white surface is maximum and minimum on
the black surface. When the sensor is above the black line, the IR receiver
receives negligible infrared signal emitted by the IR transmitter. In the case of
white surface, the IR receiver receives the signal. Then the IR receiver gives an
output which can be used by the Arduino as an input. When the sensor senses
white surface then the Arduino gets 0 as input and when it senses black line the
Arduino gets 1 as input.
Depending upon the input from the IR sensors attached to the robot in different
directions, the Arduino controls the movement of the robot with the help of a
motor driver. The motor driver divides the voltage from the power supply among
the two motors and Arduino. Based on the voltage supplied to two motors , the
motor can rotate the wheel of the robot in the appropriate direction. We can
change the turning speed using Arduino.Regarding the coding part, we can use
Casewise/Conditional high-lows or PID algorithm to follow the line.
## PID Algorithm
PID algorithm consists of three basic coefficients; proportional, integral and derivative which are varied to get optimal response. Closed loop systems, the theory of classical PID and the effects of tuning a closed loop control system are discussed in this paper. The system output (also called the process variable) with a sensor and compared to the reading to the reference value (also called the set point). Reference and the measured output are compared and the result is an error value which is used in calculating proportional, integral, and derivative responses. Summing the three responses to obtain the output of the controller. The output of the controller is used as an input to the system you wish to control, changing some aspect of the system. In practical terms, it automatically applies an accurate and responsive correction to a control function. This means that the robot will no longer oscillate and will be able to take different types of curves at different curve radius without getting off the line. To make it easier to understand the program, we will use an integral called error. It can be both positive and negative. 
![image](https://github.com/rtcniser/Line-Follower/assets/53950536/bcb14717-3759-43b7-8f1e-30862fe0d338)
The distinguishing feature of the PID controller is the ability to use the three control terms of proportional , integral and derivative influence on the controller output to apply accurate and optimal control.For each term, it corresponds to a constant, Kp , Ki and Kd , that must be adjusted so that the robot can follow a line without oscillating or slowing down or getting off the track. 
- Here, the proportional term is the error. It directly controls how to take the curves - if Kp is a small value he will take the curves easier (he will go almost straight); if it is a large value    it will take the curves suddenly (either it will oscillate on a straight line, or it will take the curve too tight and it will leave the track).
- The integral term accumulates all errors. The integral term seeks to eliminate the residual error by adding a control effect due to the historic cumulative value of the error. When the error is     eliminated, the integral term will cease to grow. This will result in the proportional effect diminishing as the error decreases, but this is compensated for by the growing integral effect . In     other words, it helps the robot stop oscillating. But at a Ki that is too high, it will do the opposite.
- The derivative term calculates the current error and the last error. When the robot suddenly hits a tight curve, this value will be high and will force the robot to take the required curve. The     more rapid the change, the greater the controlling or dampening effect . At a Kd too small, this value might not take place. At a Kd too high, it can give errors to the whole program and the        robot can oscillate, run very slowly or take very narrow curves that don't even exist.
In our bot we mainly use the PD algorithm instead of PID algorithm.
# Code (Arduino)
Written on Arduino. There are two version: 
- Casewise/Conditional high-lows (_Used in NIRMAN-2.0_)  
    Codes: v0 and v3   
- PID (_Used in Wissenaire-23_)  
    Codes: v20,v21,v22,v32,v4
    v4 being the latest.  
    _Note_  that v4 code has an `speed(255,255)` in `//sharp left` case. This was a deliberate change to account for the multiple left turns in the track. This also helped in escaping a right loop, significantly reducing lap time.
# Circuit
Generic Design for motors with 5 sensors to arduino.
### Wirings
![image](https://github.com/rtcniser/Line-Follower/assets/53950536/e95436d7-63af-44c6-8ded-38bf1dd8590b)

# Chassis 
### Design
- 17cm (height) X 14cm (width) body.
- Front panel to stick IR sensors
- Cover panel to sandwich and hold the motors.

Since the cut was made on 5mm acrylic, the front panel was not required in the final setup. _Note_ that using the front panel keeps all the sensors one line, as in a generic setup. _Otherwise_ it stays in an inverted V shape which can give some strategical advantage (like detecting crosses better).
### Irregularities/Errors 
The top screw holes might be a bit off. 
# Members
Aditya Kamble (Captain) - Chassis Design, Co-ordination  
[Vishal Meena](https://github.com/CodeScythe0) - Code, Algorithm  
Aayush Jelmeria - Co-ordination, Track Design  
Karan K. Sahoo - Chassis Design, Algorithm, Documentation
Sanat K. Behera - Chassis Design, Circuit  
S. Mahesh (Mentor) - Code, Algorithm, Working Idea  
[Girija S. Ray](https://github.com/Alpha3125) (Mentor) - Code, Track Design, Circuit, Documentation
