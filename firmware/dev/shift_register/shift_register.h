#ifndef SHIFT_H
#define SHIFT_H

#include <stdlib.h>
#include <string.h>
#include "sys/port.h"
#include "lib/delay/delay.h"

typedef struct Shift_register{
	char *data;
	unsigned int size;
	Pin *serial;
	Pin *latch;
	Pin *clk;
}Shift_register;

Shift_register* shift_register_new(unsigned int size, Pin *serial, Pin *clk, Pin *latch);
void shift_register_latch_output(Shift_register *shift_register);
void shift_register_data(Shift_register *shift_register, char *data);


#endif
