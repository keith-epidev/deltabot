#include <msp430.h>
#include "etc/byte.h"
#include "lib/delay/delay.h"
#include "sys/port.h"
#include "dev/stepper/stepper.h"

int main(void){
        WDTCTL = WDTPW + WDTHOLD;       // Stop WDT

	
        Stepper *stepper = stepper_init(&P2);

	while(1)
	stepper_step(stepper);



}
