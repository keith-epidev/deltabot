#ifndef POSITION_H
#define POSITION_H

#include "sys/port.h"

extern volatile  double x;
extern volatile  double y;
extern volatile  double z;

extern volatile  double a1;
extern volatile  double a2;
extern volatile  double a3;

extern volatile  double a1_step;
extern volatile  double a2_step;
extern volatile  double a3_step; 

extern volatile  double distance;
extern volatile  double displacement;

extern volatile  double a1_cycle;
extern volatile  double a2_cycle;
extern volatile  double a3_cycle;

extern volatile int hold_on;


void calc_position();

#endif
