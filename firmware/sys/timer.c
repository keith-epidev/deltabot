//timer.c
#include "sys/timer.h"

enum timer_mode{
        STOP = 0,
        UP = 1,
        CONTINUOUS = 2,
        UP_DOWN = 3
};



Timer TA = {(byte *) TACTL_,(byte *) TAR_,(byte *)  TACCTL0_,(byte *) TACCR0_, (byte *)TACCTL1_,(byte *)TACCR1_};



void timer_setup_pwm(Timer *timer,int period){
*timer->ccr0 = 1000-1;
pwm_set_period(timer,period);

*timer->cctl1 = OUTMOD_7;
*timer->ctl = TASSEL_2 + MC_1;
}



void pwm_set_period(Timer *timer,int period){
*timer->ccr1 = period;
}
