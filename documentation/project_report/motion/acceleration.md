Acceleration
============

Acceleration is required to ensure smooth motion is maintained. Smooth motion is essential for reaching high speeds and also to minimise a stepper motor skipping a step. The rate of acceleration can be written as a function of current and next frames momentum.  We are only concerned with the momentum of the actuator carriages, not the momentum of the platform.

## P = mv ##
where #P# is momentum,
#m# is mass,
#v# is velocity.
So to decrease momentum around sharp bends, we must reduce the speed of the actuator.

Once the system has been constructed, we will need to run tests to work out the maximum speed that we should attempt to accelerate to. Jerk is the derivative of acceleration. It can be thought of as how fast can we accelerate? This also will need to be thoroughly tested. But we can write it as a variable so that we can later substitute different values.


The acceleration algorithm is as follows:

- calculate the closest change in direction for any actuator
- if change is less then 100 steps decrease speed by A
- if change is greater then 100 increase speed by A
- if maximum speed has been reached do nothing.
- repeat next step


This creates a smooth linear acceleration. We could also implement more detailed patterns that perhaps use a quadratic to reach the maximum speed sooner.
