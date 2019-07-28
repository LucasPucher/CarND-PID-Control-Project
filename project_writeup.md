# CarND-PID-Control-Project

   
## 1. Introduction
This is the report for the project PID Control of the Udacity Self Driving Car Nanodegree.


## 2. Simulator
The project is based on controlling a vehicle in the Udacity Term 2 Simulator.

A pid control is introduced to keep the vehicle on the track.


## 3. PID Parameters
The parameters were chosen by manual tuning. A twiddle approach was attempted, however it takes long to converge (due to simulation running in real time) and in this case the twiddle diverged which cause the vehicle to fall out of the track - no automatic restart of the simulator was possible.

### 3.1 P Parameter
The P parameter controls the amount of error which will be corrected by the controller.

Setting this parameter too high caused the vehicle to oscillate between left and right at a high rate. I could not find a value which made the controller work, but I chosed initially a value of 0.5, which was suitable as a starting point.

### 3.2 D Parameter
Next I tuned the D parameter. This parameter controls the stability of the controller, since it anticipates the amount of correction based on the rate of change of the steering angle. 
Setting this parameter too high (for example 10.0) made the vehicle to be continiously steering and therefore the speed lowered.
Setting this parameter too low (< 1) loses the effect of stability.
After changing both P and D I found a good compromise in P = 0.2 and D = 2.

It is to note that the vehicle fulfilled all criteria by just tuning these two parameters.

### 3.3 I Parameter
The I parameter controls the systematic bias. In our case the vehicle was driving good enough with PD, but if the wheels were misaligned, we could never drive in the middle of the road. In our case this offset was not very noticeable.

What I found out is that this parameter has to be really small (0.002 in my case). Increasing this parameter adds a lot of instability in the controller, because the integration over time of the error gets very big and the other two terms are not able to compensate it.

## 4. Conclusions and reflection
This was a simple project for manual tuning. 
An improvement could be to try to find out the model of the car to be able to apply twiddle to find the optimum parameters for the controller. Another improvement might be to control the speed also by using a PID.


