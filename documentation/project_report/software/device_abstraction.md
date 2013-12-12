Device Abstraction
==================

Coming from a Computer Science background I felt it was necessary to try and force my devices into abstracted structures. The aim is to cleanly recycle as much code as possible while promoting clean and readable code.

``
typedef struct LCD{
	Spi *spi;
	int col;
	int row;
	int cursor;
	Pin *rst;
	Pin *mode;
	Pin *enb;
	CircularBuffer *buffer;
}LCD;
``
For example UART, SPI, position queue implement the same CircularBuffer structure. Each time a new 'device' is created a new instance of a CircularBuffer is instantiated and its pointer is then associated to it. Furthermore, say we required 10 LCDs on a single SPI line. We can now simply create an array of LCD type and instantiate instances of a LCD. The flexibility is a clear advantage. Using this method of code recycle also reduces the amount of flash storage required to hold the program. Since the patterns are clearly described and reused, the compiler only needs to store the functions associated with an LCD once. If the code was written inline, the compiler would not be able to efficiently optimise the code.

However the drawbacks may force you into inline code depending on the application. The biggest issue is that for every execution of a abstracted LCD command adds an additional JMP command. This is one extra clock cycle opposed to inline code. However if speed is an issue, the inline function keyword can be used to tell the compiler to copy the following code instead of jumping to it. This obviously bloats your program size fast so it should be used sparingly.
