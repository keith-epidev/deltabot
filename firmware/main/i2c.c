#include <msp430.h>
#include "etc/byte.h"
#include "sys/port.h"
#include "dev/uart/uart.h"
#include "lib/bus/i2c_master/i2c.h"


int main(void){
	WDTCTL = WDTPW + WDTHOLD;	// Stop WDT


	Pin P1_0 = pin_new(&P1,0);	//CLK
	Pin P1_1 = pin_new(&P1,1);	//TXD
	Pin P1_2 = pin_new(&P1,2);	//RXD
	
	I2C i2c = i2c_master_new(&P1_0,&P1_1,&P1_2);

	while(1){
		//1st chip on
		i2c_master_put(&i2c,"A1");
		i2c_master_put(&i2c,"B1");
		i2c_master_put(&i2c,"C1");
__delay_cycles (100000);
		i2c_master_put(&i2c,"A0");
		i2c_master_put(&i2c,"B0");
		i2c_master_put(&i2c,"C0");
__delay_cycles (100000);
	}

	return 1;
}
