Sensory input
=============

To determine where the platform is in the work space, the printer must first 'home'. This is the act of synchronising the memory coordinates with the actual physical coordinates. It can be achieved by firstly, moving all actuators to the top of the rails. A sensor triggers when the carriage has reached the very top so that the motor can stop. Once all carriages have reached the very top, the platform is sent back down towards the base. This is done by moving all carriages at the same time. Another sensor detects when the tool end has just touched the platform signalling the end of travel. Once this occurs, all software variables #(x,y,z)# can be set to 0 indicating a homed tool.

The top 'end stops' have been implemented with Photo-interrupter modules. These have a IR LED that shine a beam of light into a photo-transistor. If something gets in the way of this beam, the transistor will switch off. In this case, a small height adjustable square plate attached to the carriage breaks the IR beam. See figure x

![Photo-interrupter](endstop.jpg)


The bottom plate contact is currently triggered when the tool end tip touches the grounded plate. The tip is pulled high through a 10K resistor and this level is monitored by a transistor. When a contact is made the transistor's base is forced low signalling the end of travel has occurred. While this produces great results, it is not practical in the long run once we move away from a copper plate. It would be nice to print on a fibreglass board so it can be removed. Fibreglass is not conductive so the current method will not work.

A possible alternative is to use a switch that can be retracted during print. This possible adds a servo to the tool end increasing weight. Another alternative would be to use a IR range finding system. While complex, it would mean that the platform could race towards the base but slow down as it approaches the base. It also would be extremely light weight as the only components required are a LED and a photo transistor.
