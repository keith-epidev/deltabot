#ifndef SPI_H
#define SPI_H

#include "sys/port.h"
#include "lib/buffer/CircularBuffer.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Spi{
	CircularBuffer *in;
	CircularBuffer *out;
	char cts;
}Spi;


Spi *spi_init();

void spi_write(char *data);
void spi_put(char data);

/*
void uart_put_printf(char data, FILE *stream);
byte uart_read();
void uart_get();
char uart_new_line();
*/
#endif
