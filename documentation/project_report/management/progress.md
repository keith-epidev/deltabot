Progress
========

A two complete frame has been designed and assembled. The first desktop model has a print area of roughly #10cm^3#. The second was a larger version using all the same printed parts but increasing the rod lengths. It is twice as tall and wide, resulting eight times the volume. This design has had small revisions made along the way and seems quite stable. The larger version does require a double cross strut for stability.

A plotter attachment was developed first for testing purposes. This has been used extensively. The extruder feed has also been prototyped although it has not been properly tested.

The second revision of electronics has been assembled and tested. While far better then the first revision, a third would add extra features and improve stability. No hardware mods are required for basic functionality.

The firmware has been developed during the entire development stage. Slowly improving and adding additional features. Currently it supports:
- Queuing of motion instructions
- Acceleration
- Console interface over UART
- LCD interface
- Homing and auto height calibration
- Command checksum validation


The complementary computer software is currently stable for 2D plots. It takes g-code generated from slic3r and converts it to motion descriptions for the printer. The communication side is capable of sending the instructions and validating that they were successfully received.

Shortcomings
-----------
For a complete working 3D printer the following tasks need to be completed:

- Develop extruder calculations for software
- Implement extruder feeder control
- Implement temperature PID loop
- Extend auto calibration


