Methodology
==========

The first iteration of electronics were designed around the goal of modularity. While it offered the needed flexibility during the prototyping stage, a few shortcomings forced a redesign. It featured small daughter boards that vertically plugged into a mainboard. Exposing a SPI bus as ports that could accept any type of add on provides a possible upgrade path in the event of a necessary addition. 

![First iteration of electronics](modular.jpg)

Unfortunately this configuration was too flimsy. Stepper drivers were damaged during testing. There is a lot of manual work required to assemble such a design and would not be practical for a final product.

The second revision was designed to be a simple low-cost single board solution. Instead of being a complete standalone product, this version is designed to leverage of a host computer. No external memory is used so a computer must constantly feed G-Code commands during a print. 

![Second revision](electronics.jpg)


One of the main goals of revision two was to be cross compatible with the exiting community firmware. The most compatible firmware is ['Teacup'](http://github.com/Traumflug/Teacup_Firmware) . Furthermore, any software that I develop should be cross compatible with existing hardware such as RAMPS.


