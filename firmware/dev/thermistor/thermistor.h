#ifndef THERMISTOR_H
#define THERMISTOR_H

#include "sys/port.h"
#include <avr/interrupt.h> 
#include <stdlib.h>

extern volatile int temp[1000];

void thermistor_init();
double thermistor_get_c();

#endif
