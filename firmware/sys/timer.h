#ifndef TIMER_H
#define TIMER_H

#include <msp430.h>
#include "etc/byte.h"



typedef const struct Timer{
	byte volatile *ctl;
	byte volatile *range;
	byte volatile *cctl0;
	byte volatile *ccr0;
	byte volatile *cctl1;
	byte volatile *ccr1;
}Timer;


extern Timer TA;

void timer_setup_pwm(Timer *timer,int period);
void pwm_set_period(Timer *timer,int period);


#endif
