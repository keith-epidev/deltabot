#ifndef STEPPER_H
#define STEPPER_H

#include "sys/port.h"
#include <avr/interrupt.h> 
#include <stdlib.h>

typedef struct Stepper{
	Pin *step;
	Pin *direction;
	Pin *enable;
}Stepper;


Stepper *stepper_init(Pin *step, Pin *direction, Pin *enable);
void stepper_step(Stepper *stepper);
void stepper_dir(Stepper *stepper,int dir);
void stepper_start_frame();

#endif
