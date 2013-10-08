#include "stepper.h"

Stepper* steppers[4];
int speed = 40;
int steps = 0;
int s = 0;

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

   sei(); //  Enable global interrupts 

   OCR1A   = speed; // Set CTC compare value to 1Hz at 1MHz AVR clock, with a prescaler of 64 

   TCCR1B |= ((1 << CS10)) | (1 << CS11); // Start timer at Fcpu/64 


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

steps++;

//for(int i = 0; i < s; i++)
	pin_toggle(steppers[i]->step);

if(steps == 2000){
//	for(int h = 0; h < s; h++)
		pin_toggle(steppers[i]->direction);
//	steps=0;
}

if( steps == 4000){
		pin_toggle(steppers[i]->direction);
i++;
if( i == s)
i = 0;
steps = 0;
}

}
