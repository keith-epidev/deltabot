#include <msp430.h>
#include "etc/byte.h"
#include "sys/port.h"
#include "dev/lcd/3310/3310.h"

#define speed 100000

int main(void){
	WDTCTL = WDTPW + WDTHOLD;	// Stop WDT


	Pin P1_0 = pin_new(&P1,0);	//clk
	Pin P1_1 = pin_new(&P1,1);	//mosi
	Pin P1_2 = pin_new(&P1,2);	//d/c
	Pin P1_3 = pin_new(&P1,3);	//rst
	Pin P1_4 = pin_new(&P1,4);	//sce1


	LCD *lcd = lcd_new( &P1_0, &P1_1, &P1_2, &P1_3, &P1_4);

	write_string(lcd,"Screen one.");


	return 1;
}
