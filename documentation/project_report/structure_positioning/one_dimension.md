Simple one dimension motion
===========================

Lets consider one dimension to begin with, Figure 1 illustrates the movement of three key points; the platform and the left and right linear actuators. We can see that if the linkages are the same length as the vertical distance, the platform is capable of reaching any position along the x axis.

[Simple ideal motion](svg:1)

Also, it can be seen that a vertical actuator requires an equal amount of travel to permit full movement. It is important to note that the platform is considered a point source in this example. Practically this is not the case as we will require a place to mount tools.

For a desired position of 𝒑(𝒙), we need to derive where to place linear actuators. Take figure [3] below, lets derive the equations that will translate a desired 𝒙 into 𝒂₁ and 𝒂₂. 

[Simple one dimension parameters](/img/structure_derive.svg)

Firstly, lets derive relationship between 𝒙 and 𝒂₁:
$$ (1)  h^2 = a^{2}_{1} + b^{2}_{1}$$
$$  \Leftrightarrow  a_{1} = \sqrt{ h^2 - b^{2}_{1} }$$
$$ (2) x = b_1 - D/2$$
$$  \Leftrightarrow b_1 = x + D/2$$
substituting (1) into (2) gives
$$ a_1(x) = \sqrt{ h^2 - ( x + D/2 )^2 }$$
Now, lets find the relationship between 𝒙 and 𝒂₂:
$$ (3)  h^2 = a^{2}_{2} + b^{2}_{2}$$
$$  \Leftrightarrow  a_{2} = \sqrt{ h^2 - b^{2}_{2} }$$
$$ (4) b_2 = D - b_1$$
substituting (2) into (4) gives
$$b_2 = D - (x + D/2)$$
$$\Leftrightarrow  b_2 =  D/2 - x$$
finally, substituting (4) into (3)
$$ a_2(x) = \sqrt{ h^2 - (D/2 - x)^2 } $$
