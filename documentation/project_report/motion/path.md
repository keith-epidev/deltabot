Path Tracing
============

Once a three dimensional object has been split up into two dimensional layers, the extruder head must trace the outlines of each layer. Once a layer has been traced, the z component moves a step down and the extruder will trace the next layer. The process repeats until all layers have been extruded leaving a fully formed three dimensional object.

To move the extruder in a desired direction, we must calculate the distance and direction that each actuator must travel. This can be done by subtracting actuator heights from the last position with the heights of the next move. This gives us three vectors describing the distance and direction. The next step is to translate these distances into corresponding speeds. To move in a straight line, each actuator must complete their respective distances at the same time. 

So to calculate how fast each actuator must move, we first start with:

## speed = displacement / \Delta time ##

So we can see that keeping the time constant for all three actuators, only displacement affects speed. Actually speed is directly proportional to the distance that needs to be travelled. 

But how long is an acceptable time to travel? This is quite simple once the maximum speed is determined. The actuator with the largest displacement should travel at maximum speed.

## \Delta time = displacement / MAX(speed) ##

Now we simply substitute the same #\Delta time# for the other actuators. Now we have proportional motion! 
