Major Constraints
=================

The most obvious constraint is the processing power of the small microcontroller. A 10Mhz 8-bit CPU isn't the most impressive piece of hardware. Operations on ints and longs will take multiple clock cycles. Without a FPU any float operations will take a considerable amount of time. However, if we are careful with our design and execution, issues associated with these constraints can be mitigated.

The answer is to pre-process incoming data and cache it for future use. By implementing a queue like system we can evaluate and save upcoming tasks while the processor is not active. As long as we can queue up and process the commands faster then they are executed, the system will remain constantly active.

A work around is to simply offload a complex task to the host computer. For example, we will not transmit a raw STL file to the board. This would require the board to process a large 3D description and slice it into layers. This is actually relatively power hungry and while possible, it would be much more efficient to run an existing solution on a computer.

Furthermore running components on a computer opens up debugging options. We can simulate a part of the program in real time and visual display the results on a screen. Doing so will may increase development time, but it also is a safer option considering the time constraints. Having greater debugging utilities should speed up the prototyping stage. Once working, individual components can be shifted to the board in iterations to slowly confirm correct operation.
