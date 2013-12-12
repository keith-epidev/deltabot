Positioning
==========

The heights of the actuators are calculated with the following equations:

``
var a1 = z + Math.sqrt( r2 - Math.pow( dist( x, (y +pr) - D ),2) );
var a2 = z + Math.sqrt( r2 - Math.pow( dist( (x-.5*pr )+ root3*D/2, (y - root32*pr) + D/2 ),2) );
var a3 = z + Math.sqrt( r2 - Math.pow( dist( (x+.5*pr) - root3*D/2, (y - root32*pr ) + D/2 ),2) );
``

This is implemented on the host computer and written in JavaScript. Following those calculations, we need to determine the speeds and distance required. This is achieved by first determining which actuator needs to travel the furthest. Then we calculate the speed as a ratio that will make the carriage travel its distance in the same amount of time as the other carriages. This is simply the distance divided by the largest distance.

