#ifndef UART_H
#define UART_H

#include "sys/port.h"
#include "lib/buffer/CircularBuffer.h"
#include <stdlib.h>

typedef struct Uart{
	CircularBuffer *in;
	CircularBuffer *out;
	char new_line;
}Uart;


Uart *uart_init();

void uart_write(char *data);
void uart_put(char data);
byte uart_read();
void uart_get();
char uart_new_line();
#endif
