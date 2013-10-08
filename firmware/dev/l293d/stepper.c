#include "stepper.h"

const static byte map[] = {
	b0|b1,
	b1|b2,
	b2|b3,
	b0|b3
};

void step(Stepper *stepper, int i );

Stepper *stepper_init(Port *port){
	Stepper *stepper = (Stepper * ) malloc( sizeof( Stepper ) );
	stepper->port = port;
	stepper->dir = 0;

	port_config_out(port);
	port_low(port);

	return stepper;
}

void stepper_step(Stepper *stepper){

	if(stepper->dir == 0)
	for(int i = 0; i < 4; i++){
		step(stepper,i);
	}	
	else
	for(int i = 3; i >= 0; i--){
		step(stepper,i);
	}	

}


void step(Stepper *stepper,int i ){
	port_set(stepper->port, map[i]);
		__delay_cycles (4000);
}

void stepper_dir(Stepper *stepper,int dir){
	stepper->dir = dir;
}
