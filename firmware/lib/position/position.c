//serial.c
#include "position.h"
#include "../../dev/stepper/stepper.h"
#include "../../sys/console.h"
#include <math.h>

#define D 130
#define r 30
#define SCALE 64

volatile  double x = 0;
volatile  double y = 0;
volatile  double z = 0;

volatile  double a1 = 0;
volatile  double a2 = 0;
volatile  double a3 = 0;


volatile  double a1_step = 0;
volatile  double a2_step = 0;
volatile  double a3_step = 0; 

volatile  double a1_cycle = 0;
volatile  double a2_cycle = 0;
volatile  double a3_cycle = 0;

volatile  double distance = 0;
volatile  double displacement = 0;

volatile int hold_on = 0;

void calc_position(){
	 double a1_temp,a2_temp,a3_temp,a1_dist,a2_dist,a3_dist;
	
/*t
	a1_temp = sqrt(pow((sqrt(3)*D)/3 - y + r ,2) + pow(x,2));
	a2_temp = sqrt(pow(D/2 + x - r/2,2) + pow( sqrt(3)*D/6 + y - sqrt(3)*r/2,2));
	a3_temp = tsqrt(pow(D/2 - x + r/2,2) + pow( sqrt(3)*D/6 + y - sqrt(3)*r/2,2));
	printf("x:%g\n",x);
	printf("y:%g\n",y);
	printf("z:%g\n",z);

	printf("a1:%d\n",a1);
	printf("a2:%d\n",a2);
	printf("a3:%d\n",a3);
*/
	a1_dist =  x - a1;
	a2_dist =  y -a2;
	a3_dist = z - a3;
/*
	printf("a1_d:%g\n",a1_dist);
	printf("a2_d:%g\n",a2_dist);
	printf("a3_d:%g\n",a3_dist);
*/
	a1 = x;
	a2 = y;
	a3 = z;


	if(a1_dist > 0)
		pin_low(steppers[0]->direction);
	else
		pin_high(steppers[0]->direction);

	if(a2_dist > 0)
		pin_low(steppers[1]->direction);
	else
		pin_high(steppers[1]->direction);

	if(a3_dist > 0)
		pin_low(steppers[2]->direction);
	else
		pin_high(steppers[2]->direction);


	a1_cycle = 0;
	a2_cycle = 0;
	a3_cycle = 0;

	if(abs(a1_dist) >=abs(a2_dist) && abs(a1_dist) >= abs(a3_dist)){
		a1_step = SCALE;
		if(a2_dist != 0)
		a2_step = abs(a1_dist*SCALE/a2_dist);
		else
		a2_step = -1;
		if(a3_dist != 0)
		a3_step = abs(a1_dist*SCALE/a3_dist);
		else
		a3_step = -1;
//	printf("1:%i\n2_:%i\n3:%i\n",a1_step,a2_step,a3_step);
		distance = abs(a1_dist*2*SCALE);
	}else
	if(abs(a2_dist) >= abs(a1_dist) && abs(a2_dist) >= abs(a3_dist)){
		a2_step = SCALE;
		if(a1_dist != 0)
		a1_step = abs(a2_dist*SCALE/a1_dist);
		else
		a1_step = -1;
		if(a3_dist != 0)
		a3_step = abs(a2_dist*SCALE/a3_dist);
		else
		a3_step = -1;
//	printf("1:%i\n2_:%i\n3:%i\n",a1_step,a2_step,a3_step);
		distance = abs(a2_dist*2*SCALE);
	}else
	if(abs(a3_dist) >= abs(a1_dist) && abs(a3_dist) >= abs(a2_dist)){
		a3_step = SCALE;
		if(a1_dist != 0)
		a1_step = abs(a3_dist*SCALE/a1_dist);
		else
		a1_step = -1;
		if(a2_dist != 0)
		a2_step = abs(a3_dist*SCALE/a2_dist);
		else
		a2_step = -1;
//	printf("1:%i\n2:%i\n3:%i\n",a1_step,a2_step,a3_step);
		distance = abs(a3_dist*2*SCALE);
	}
/*
	printf("a1s:%g\n",a1_step);
	printf("a2s:%g\n",a2_step);
	printf("a3s:%g\n",a3_step);
*/
//	printf("d%g\n",distance);


//	steppers_enable();



}
