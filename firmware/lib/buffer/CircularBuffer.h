#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include "etc/byte.h"

typedef struct CircularBuffer{
	char *buffer;
	unsigned int start;
	unsigned int end;
	unsigned int size;
}CircularBuffer;

CircularBuffer *circular_buffer_new(unsigned int size);
void circular_buffer_put(CircularBuffer *buffer, char c);
void circular_buffer_putstr(CircularBuffer *buffer, char *str);
char circular_buffer_get(CircularBuffer *buffer);
char circular_buffer_isempty(CircularBuffer *buffer);


#endif
