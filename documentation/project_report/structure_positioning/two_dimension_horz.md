Two dimensional position in the horizontal plane
==============================================

Now its time to examine how adding a third actuator allows for two dimensional movement in the horizontal plane. Figure ref[top-view_diagram.svg] is a top-down view of our system. The actuators are placed in a equilateral triangle formation to distribute the load evenly. The position of the platform can be altered by changing the lengths of the linkages horizontal component, the #b# term. Remember, this is not stretching the linkages, it is merely displacing length between the horizontal and vertical component - the hypotenuse remains the same. By looking straight down into the system, only the #b# vectors are visible, the carriages on the rails or the #a# term is  directed in/out of the page.

The coordinates system has been aligned with the actuators to help simplify the problem. The origin is placed at the centre of the print bed. Please note that the print bed is represented as a circle with its radius equal to the minimum distance from the origin to the frame. 

To control the platforms position we must modify the carriages vertical position #a#. However, the horizontal plane position is completely dependent on #b#. We have already established the relationship between #a# and #b#, and that is #a = \sqrt{ h^2 - b^2}#. We now need to develop the relationship between #b# and the position (#x,y)#.

Each actuator will have its own equation for calculating its #b# term. This is because they are not placed uniformly around the coordinates system even though they are equally apart. Firstly, the general rule for calculating #b# as a function of the platforms position:
##b_n(x,y) = |\overrightarrow{R_n P(x,y)}|## Where R is the position vector of the target actuator and P is the position vector of the platform.

![Top view components](top-view_diagram.svg)

Figure ref[top-view_diagram.svg] illustrates that this problem can be solved by a simple application of Pythagoras' theorem again.

Top actuator:
##d_1(x) =  x##
##e_1(y) =  y - D##
##b_1(x,y) = \sqrt{d_1^2 + e_1^2}##
##b_1(x,y) = \sqrt{ x^2 + (y - D )^2}##
Bottom left actuator:
##d_2(x) = x - (-d\sqrt{3}/2)##
##e_2(y) = y - (-d/2)##
##b_2(x,y) = \sqrt{ ( x + {d\sqrt(3)\over 2})^2 + ( y + {d\over 2})^2   } ##
Bottom right actuator:
##d_3(x) = x - D\sqrt{3}/2##
##e_3(y) = y - (-D/2)##
##b_3(x,y) = \sqrt{ ( x - {D\sqrt(3)\over 2})^2 + ( y + {D\over 2})^2   } ##
