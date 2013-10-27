#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include "sys/port.h"
#include <avr/interrupt.h> 
#include <stdlib.h>


typedef struct Debounce{
	Pin *pin;
	char *state;
	char *last_state;
}Debounce;


#endif
