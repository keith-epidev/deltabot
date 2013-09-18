#ifndef STEPPER_H
#define STEPPER_H

#include "sys/port.h"
#include <stdlib.h>

typedef struct Stepper{
	Port *port;
	int dir;
}Stepper;


Stepper *stepper_init(Port *port);
void stepper_step(Stepper *stepper);
void stepper_dir(Stepper *stepper,int dir);

#endif
