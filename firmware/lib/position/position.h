#ifndef POSITION_H
#define POSITION_H

#include "sys/port.h"

extern volatile int x;
extern volatile int y;
extern volatile int z;

extern volatile int a1;
extern volatile int a2;
extern volatile int a3;

extern volatile int a1_step;
extern volatile int a2_step;
extern volatile int a3_step; 

extern volatile int distance;

extern volatile int a1_cycle;
extern volatile int a2_cycle;
extern volatile int a3_cycle;


void calc_position();

#endif
