#include "etc/byte.h"
#include "etc/config.h"
#include "sys/port.h"
#include "sys/console.h"
#include "dev/uart/uart.h"
#include "dev/thermistor/thermistor.h"


#include <util/delay.h>
#include <avr/interrupt.h> 


int main(void){
	Uart *uart = uart_init();
	console_init();

	thermistor_init();

	pin_config_out(heat);
	pin_high(heat);
	
	console_prompt();


	return 1;
}


/*
void disp_temp(void){
int disp = temp*1024;
disp = disp/3.3; //make sure float after


}
*/
