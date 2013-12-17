Speed
=====

A simple vertical speed test shows that the system is capable of relatively slow speeds.

Time taken to travel 10.3cm was 5.4 seconds.
## speed = distance  / time ##
## speed = 0.0190740741 m/s ##


Currently, a combination of a high micro-stepping configuration and low system clock speed is limiting the speed of the stepper motors. By reducing the micro-stepping speed from 1/32 to 1/8, the step wave period can be decreased by four times. That is, the stepper drivers can be signalled four times faster. Increasing the clock speed from 10Mhz to 20Mhz will also double the possible speeds by twice and furthermore increase acceleration resolution by selecting a smaller clock divide for the stepper service routine.

So this is a possible speed increase of eight times. However, we must realise that we have not yet experimented with the physical limitations. This will need to be thoroughly tested. The acceleration and jerk variables will need to be calibrated.
