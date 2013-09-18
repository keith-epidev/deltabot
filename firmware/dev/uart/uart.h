#ifndef UART_H
#define UART_H

#include "sys/port.h"
#include "lib/buffer/CircularBuffer.h"
#include <stdlib.h>

typedef struct Uart{
	Pin *tx;
	Pin *rx;
	CircularBuffer *in;
	CircularBuffer *out;
}Uart;


Uart *uart_init(Pin *tx, Pin *rx);
void uart_put(Uart *uart, char c);
void uart_putstr(Uart *uart, char *str);
char uart_receive() ;

#endif
