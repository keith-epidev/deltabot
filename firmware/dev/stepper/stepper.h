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

extern volatile Stepper* steppers[4];

Stepper *stepper_init(Pin *step, Pin *direction, Pin *enable);
void steppers_enable();
void steppers_disable();
void stepper_step(Stepper *stepper);
void stepper_dir(Stepper *stepper,int dir);
void stepper_start_frame();
void set_speed(int s);

#endif
