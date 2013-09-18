#include <msp430.h>
#include "etc/byte.h"
#include "lib/delay/delay.h"
#include "sys/port.h"
#include "dev/shift_register/shift_register.h"

#define speed 100000
unsigned int wdtCounter = 0;


static char map[] = {
	b7|b6|b5|b4|b3|b2, 	//0
	b6|b5,			//1
	b7|b6|b1|b3|b4,		//2
	b4|b6|b5|b1|b7,		//3
	b2|b1|b6|b5,	 	//4
	b7|b2|b1|b5|b4,		//5
	b7|b2|b1|b3|b4|b5,	//6
	b7|b6|b5,		//7
	b7|b2|b6|b1|b3|b5|b4,			//8
	b7|b2|b6|b1|b5		//9
	};


static char hours = 18;
static int mins = 15;
static int secs = 0;

static char str[] = {1,8,1,5};
static int buzz = 5;

void inc_sec(){
	secs++;
	buzz = 0;

	if(secs > 59){
	mins++;
	secs = 0;


	if(mins > 59){
	hours++;
	mins = 0;
	}

	if(hours > 23){
	hours = 0;
	}



	//translate to lcd

	str[3] = (mins%10);	
	str[2] = ((mins/10)%10);	
	str[1] = (hours%10);	
	str[0] = ((hours/10)%10);	


	}
	


}


int main(void){

	WDTCTL = WDT_MDLY_32;
	IE1 |= WDTIE;


	Pin P1_5 = pin_new(&P1,5);	//latch
	Pin P1_6 = pin_new(&P1,6);	//serial in
	Pin P1_7 = pin_new(&P1,7);	//shift


	Pin P1_4 = pin_new(&P1,4);	//shift
	pin_config_out(&P1_4);
	pin_low(&P1_4);

	
	Shift_register *shift_register = shift_register_new(2, &P1_6, &P1_5, &P1_7);	
	shift_register_latch_output(shift_register);

  //__bis_SR_register( LPM0_bits + GIE );
  __bis_SR_register( GIE );
	
	char buffer[2];
	while(1){
		for(int i = 0; i < 4; i++){
			buffer[0] = map[str[i]];
		
			if(i == 1){
				if(buzz < 50)	
				buffer[0] |= b0;
				else
				buffer[0] &= ~b0;
			}


			buffer[1] =  ~ ((1<<(3-i))<<4);
		shift_register_data(shift_register, buffer);
		shift_register_latch_output(shift_register);
		}
			if(buzz<100)
			buzz++;



	}

	return 1;
}


void watchdog_timer(void) __attribute__((interrupt(WDT_VECTOR)));
void watchdog_timer(void)
{
    wdtCounter++;

    /* Count 32 interrupts x 32ms = 1024ms, or about one second */
    if(wdtCounter == 32) {
        /* Toggle the LED pin */
/*
	str[0]++;

	if(str[0] > 9)
		str[0] = 0;

*/
	inc_sec();
        /* Reset the counter for the next blink */
        wdtCounter = 0;
    }

    /* Go back to low power mode 0 until the next interrupt */
//   __bis_SR_register_on_exit( LPM0_bits );
}
