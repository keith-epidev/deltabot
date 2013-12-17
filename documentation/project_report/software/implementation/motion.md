Motion
=======

Before we can write software to control the hardware, we must mathematically define the system. Lets start with the pulley. The radius of our GT2 pulley is 11.5mm. I have selected to only microstep 8 times. This should give a reasonable balance between accuracy and speed.

![Pulley diagram](radius.eps){width=40mm}

## D = 2 * \pi * r * STEP\_DEG/360 ##

So pulse on the stepper drivers STEP line will make the stepper driver increment rotation by 0.225 degrees. This rotation is translated into linear motion via the belt drive. So for every step, the carriage vertically travels 45.1519 um. Direction is controlled by either a high or low on the DIR.

So a motion frame provided from the computer is described with a distance (how many steps) and three ratios of how often a specific motor should step (equivalent to the speed). For example "1337 1 0.5 0.2" translates to "Cycle 1337 times, every cycle step X, every second cycle step Y and every fifth cycle Z".

Lets say we had a vector circle. We need to break it up into straight lines so that we can use the method explained previously. Ideally we would break it up into many small lines, but for this example we will split it up into 8 paths. To help visualise the problem, we are going to assume that we are dealing with a gantry system.


!['Physical Pixels' ](pixels.eps){width=120mm}

Firstly, the circle is broken into straight paths. From the starting point we need to travel along the y axis 1 step. So this would be described with "1 0 1 0", following that we need to move in the x and y direction one step. That is "1 1 1 0". And so on. The only difference for a delta machine is that we are not directly plotting a image, we are controlling the actuator heights as a function of the image.

But what if we need a angle other then 0,45 or 90? That is why the speed is a fractional value. If we were to plot "10 1 0.2 0" would result in an angle of 17.84 degrees.


We could divide the clock up by 1000 to support a large decimal place with accuracy. However, if we were to divide the clock by 1000, it would need to be in the order of Ghz to support decent speed. A much more convenient method is to approximate absolute steps with a running total. Firstly, we need to increment a counter associated with an actuator with its ratio every clock cycle. We then check if the counter has incremented its unit value. If so, then we should send a signal to step. This method permits usage of a much smaller clock such as 10Mhz.

Furthermore, if we attach the procedure to a timer, global speed and accretion can be controlled easily by modifying the timer compare value. This is very important when trying to push the maximum speed of the steppers. It is important to smoothly accelerate to high speeds to minimise mis-steps. Conversely, all actuators must maintain a relative speed to each other, otherwise the path will be skewed.

Acceleration can be implemented as a function of the distance to the next direction change. Basically, we need to reduce speed as a turn approaches. Then we can take advantage of long straight runs by accelerating through them. A basic 'look ahead' function has been implemented that runs through the motion queue calculating the next direction change.

