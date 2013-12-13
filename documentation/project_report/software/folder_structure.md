Folder Structure 
================

I have chosen to set the firmware directory in a way that attempt to separate non similar objects. For example system settings should not be located in the same directory as code for a LCD.

The following list illustrates the basic structure:

- *dev* contains sub folders that have code relating to physical components such as LCD and stepper motors
- *etc* contains configuration files such as clock speed, pin descriptions and macros
- *lib* contains reusable software objects such as buffers
- *main* holds different top level files (useful for different applications or tests)
- *sys* has anything to do with the microcontroller architecture
 
