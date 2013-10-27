#include "debounce.h"

Debounce *debounce_init(Pin *pin){
	Debounce *debounce = (Stepper * ) malloc( sizeof( Stepper ) );

	debounce->pin = pin;
	debounce->state = pin_get(pin);
	debounce->last_state = !debounce->state;
	debounce->time = 0;


	return debounce;
}









