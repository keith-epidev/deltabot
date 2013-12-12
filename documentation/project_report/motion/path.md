Path Tracing
============

Once a three dimensional object has been split up into two dimensional layers, the extruder head must trace the outlines of each layer. Once a layer has been traced, the z component moves a step down and the extruder will trace the next layer. The process repeats until all layers have been extruded leaving a fully formed three dimensional object.

To move the extruder in a desired direction, we must calculate the distance and direction that each actuator must travel. This can be done by subtracting actuator heights from the last position with the heights of the next move. This gives us three vectors describing the distance and direction. The next step is to translate these distances into corresponding speeds. To move in a straight line, each actuator must complete their respective distances at the same time. 

## speed = displacement / change in time ##
