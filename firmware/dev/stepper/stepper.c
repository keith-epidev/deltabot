#include "stepper.h"
#include "../../lib/position/position.h"

volatile Stepper* steppers[4];
volatile int speed = 40;
volatile unsigned int steps = 0;
volatile int s = 0;

Stepper *stepper_init(Pin *step, Pin *direction, Pin *enable){
	Stepper *stepper = (Stepper * ) malloc( sizeof( Stepper ) );
	stepper->step = step;
	stepper->direction = direction;
	stepper->enable = enable;

	pin_low(step);
	pin_high(direction);
	pin_low(enable);

	pin_config_out(step);
	pin_config_out(direction);
	pin_config_out(enable);

	steppers[s] = stepper;
	s++;

	return stepper;
}


void stepper_start_frame(){
	TCCR1B |= (1 << WGM12); // Configure timer 1 for CTC mode 
	TIMSK1 |= (1 << OCIE1A); // Enable CTC interrupt 
	OCR1A   = speed; // Set CTC compare value to 1Hz at 1MHz AVR clock, with a prescaler of 64 
	TCCR1B |= ((1 << CS10)) | (1 << CS11); // Start timer at Fcpu/64 

	sei(); //  Enable global interrupts 


}

void stepper_step(Stepper *stepper){
	pin_high(stepper->step);
	pin_low(stepper->step);

}


void stepper_dir(Stepper *stepper,int dir){
	pin_set(stepper->direction,dir);
}


int i = 0;

ISR(TIMER1_COMPA_vect) { 
if(distance > 0){

	a1_cycle++;
	a2_cycle++;
	a3_cycle++;


	if(a1_cycle >= a1_step){
		pin_toggle(steppers[0]->step);
		a1_cycle = 0;
	}
	if(a2_cycle >= a2_step){
		pin_toggle(steppers[1]->step);
		a2_cycle = 0;
	}
	if(a3_cycle >= a3_step){
		pin_toggle(steppers[2]->step);
		a3_cycle = 0;
	}


	pin_toggle(r_led);
/*
	for(i = 0; i < s; i++)
	pin_toggle(steppers[i]->step);

	if(steps == 10000){
			steps = 0;
			for(i = 0; i < s; i++)
			pin_toggle(steppers[i]->direction);
	}
*/


distance--;
}
}
