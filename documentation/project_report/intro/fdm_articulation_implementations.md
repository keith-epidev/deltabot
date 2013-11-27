FDM Articulation implementations
================================

A Cartesian Gantry structure is the most common implementation. It consists of a linear actuator for each axis of freedom. The horizontal plane generally has a sturdy rail that a bridge is mounted on, this rail permits motion in the x direction. A carriage is mounted to a rail that connects the bridge together. The carriage can move along this rail and therefore permits motion in the y direction. Lastly the carriage has a tool that is capable of actuating in and out in the z direction.

The Gantry system is a well tested framework and is industry standard. It can be found in many applications from small desktop CNC machines to huge container cranes. While the frame is very strong, each linear actuator is dependent on another. The bridge actuator has to be the strongest as it must provide enough force to move the bridge, carriage and tool. This becomes an issue for fast moving applications as the momentum will be relatively large.

The Delta robot has three vertical rails placed in the formation of an equilateral triangle. Each linear actuator moves in the same direction and has kinetic linkages that connect each carriage to a central platform. This platform can be positioned by placing each carriage at a certain height. This is an improvement over the Gantry setup because each actuator shares the load equally. It is capable of faster speeds because there is less load on the tool end.
