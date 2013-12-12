//serial.c
#include "position.h"

//hardware parameters
#define D 123.4
#define r 146.55
#define r2 r*r
#define pr 26.5
#define root3_2 sqrt(3)/2

#define CONV 32/0.21 //32 micro steps of 0.21mm 


/*
volatile  double x = 0;
volatile  double y = 0;
volatile  double z = 0;

volatile  double a1 = 0;
volatile  double a2 = 0;
volatile  double a3 = 0;
*/

volatile  double a1_cycle = 0;
volatile  double a2_cycle = 0;
volatile  double a3_cycle = 0;

//volatile long double distance = 0;
//volatile long double displacement = 0;

volatile Motion motion_queue[QUEUE_SIZE];
volatile Motion* motion_current =  &motion_queue[0];

volatile int hold_on = 0;

int start = 0;
int size = 0;

double dist(double a, double b){
	return sqrt( pow(a,2) + pow(b,2) );
}


void calc_position(double x, double y, double z){
	//TODO
/*
	double h1,h2,h3;
	//calc heights
	h1 = z + sqrt( r2 - pow( dist(x, (y+pr) - D),2) );
	h2 = z + sqrt( r2 - pow( dist((x-0.5*pr) + D*root3_2, y - pr*root3_2),2));
	h3 = z + sqrt( r2 - pow( dist((x+0.5*pr) - D*root3_2, y - pr*root3_2),2));

*/
}


void calc_speed(){
	//TODO
}


char motion_is_full(){
	return size == QUEUE_SIZE;
}


void queue_motion(long double distance, long double distance_change, double a1, double a2, double a3){
	int end = (start+size)%QUEUE_SIZE;


	//printf("queue");

	//printf("start:%i\n",start);
	//printf("end:%i\n",end);
	//printf("size:%i\n",size);
	//printf("a:%i\n",stepper_active);


	size++;	
	motion_queue[end].distance = distance;
	motion_queue[end].distance_change = distance_change;

	motion_queue[end].motor[0].dir = a1 > 0 ? 0 : 1;
	motion_queue[end].motor[1].dir = a2 > 0 ? 0 : 1;
	motion_queue[end].motor[2].dir = a3 > 0 ? 0 : 1;

	motion_queue[end].motor[0].step = fabs(a1);
	motion_queue[end].motor[1].step = fabs(a2);
	motion_queue[end].motor[2].step = fabs(a3);

	if(stepper_active == 0){
		do_motion();
		steppers_enable();
	}

}

void do_motion(){
	//printf("do\n");

	motion_current = &motion_queue[start];
	pin_set(steppers[0]->direction,motion_queue[start].motor[0].dir);
	pin_set(steppers[1]->direction,motion_queue[start].motor[1].dir);
	pin_set(steppers[2]->direction,motion_queue[start].motor[2].dir);
	
	a1_cycle = 0;
	a2_cycle = 0;
	a3_cycle = 0;
}


void shift_motion(){
	//printf("shift\n");

	start = (start+1)%QUEUE_SIZE;
	size--;

	//printf("srt%i sze:%i\n",start,size);
	if(size > 0)
		do_motion();
	else
		steppers_disable();
}
