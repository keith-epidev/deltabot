#ifndef UART_H
#define UART_H

#include "sys/port.h"
#include "lib/buffer/CircularBuffer.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Uart{
	CircularBuffer *in;
	CircularBuffer *out;
	char new_line;
}Uart;


Uart *uart_init();

void uart_write(char *data);
void uart_put(char data);
void uart_put_printf(char data, FILE *stream);
byte uart_read();
char uart_get();
char uart_new_line();
#endif
