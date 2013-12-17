Distortion
==========

Distortion describes how 'warped' an object is. This could be in the form of a skew, perspective scale or a translation. The simplest way to inspect distortion is to print a  perfect square and measure its sides. 

![Distortion](distortion.eps){width=80mm}

Our results showed a slight warp that pushed outwards along the #x# axis. On closer inspection we can see the distortion is aligned with the face of frame that runs from the south-east actuator to the south-west. This error could be associated with a not perfectly trued frame. The frame was then measured:

![Frame lengths measured](frame.eps){width=60mm}

It is clear that the frames current configuration is forcing the platform outwards as it approaches the north actuator due to the larger length in the south. We can also see a slight push to the north-west due to the length differences on the east and west frame sides.

Further tests should be conducted once the frame is correctly trued. If the problem still occurs after the frame has been trued, the model can be translated in software to correct for the distortion. A simple calibration procedure would be required on set up. 



