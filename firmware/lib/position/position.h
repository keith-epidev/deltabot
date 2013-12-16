#ifndef POSITION_H
#define POSITION_H

#include "sys/port.h"
#include "dev/stepper/stepper.h"
#include "sys/console.h"
#include <math.h>

#define QUEUE_SIZE 64


typedef struct Motion_actuator{
	char dir;
	double step;
}Motion_actuator;


typedef struct Motion{
	long double distance;
	long double distance_change;
	Motion_actuator motor[3];
}Motion;


extern volatile Motion motion_queue[QUEUE_SIZE];
extern volatile Motion* motion_current;

/*

extern volatile  double x;
extern volatile  double y;
extern volatile  double z;

extern volatile  double a1;
extern volatile  double a2;
extern volatile  double a3;


*/

extern volatile  double a1_cycle;
extern volatile  double a2_cycle;
extern volatile  double a3_cycle;

extern volatile int hold_on;


void calc_position();
void do_motion();
void shift_motion();
void queue_motion(long double distance, long double distance_change, double a1, double a2, double a3);
char motion_is_full();
int get_pos_start();
void pos_init();

#endif 
