#include <msp430.h>
#include "etc/byte.h"
#include "lib/delay/delay.h"
#include "sys/port.h"
#include "dev/shift_register/shift_register.h"

#define speed 10000
#define btn b3

 Pin *PP1_0;

int main(void){
        WDTCTL = WDTPW + WDTHOLD;       // Stop WDT


	Pin P1_0 = pin_new(&P1,0);	//led
	PP1_0 = &P1_0;
	pin_config_out(&P1_0);
	pin_low(&P1_0);

	Pin P2_3 = pin_new(&P2,3);	//btn
	pin_config_in(&P2_3);
	P2IE |= btn;
	P2IFG &= ~btn;

	//P2IFG &= ~btn;

	__bis_SR_register( LPM0_bits + GIE );
	for(;;);


	//__bis_SR_register( GIE );
	

	return 1;
}



void Port_2 (void) __attribute__((interrupt(PORT2_VECTOR)));
void Port_2(void)
{
	pin_toggle(PP1_0);

    P2IFG &= ~btn; // P1.3 IFG cleared
    __bic_SR_register_on_exit( LPM0_bits );
}

