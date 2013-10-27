#include "etc/byte.h"
#include "etc/config.h"
#include "sys/port.h"
#include "sys/console.h"
#include "dev/uart/uart.h"
#include "dev/spi/spi.h"
#include "dev/lcd/3310/3310.h"
#include "dev/thermistor/thermistor.h"


#include <util/delay.h>
#include <avr/interrupt.h> 


int main(void){

	Uart *uart = uart_init();
	console_init();
	_delay_ms(100);
	cli();
	Spi *spi = spi_init();
	sei();

	printf("running.\n");
	printf("Entering cmd mode\n");
	LCD *lcd = lcd_new(EXP1,EXP2,0);
	gotoXY(lcd,0,0);

	write_string(lcd,"-= deltabot =-\n");
	write_string(lcd,"uart      [OK]\n");
	write_string(lcd,"spi       [OK]\n");
	write_string(lcd,"lcd       [OK]\n");
	thermistor_init();
	write_string(lcd,"temp res  [OK]\n");


	while(1){
		write_stringf(lcd,"temp: %0.2f%cC\r",thermistor_get_c(),(unsigned)0x7f);
		printf("ping\n");
		_delay_ms(50);
	}	


	return 1;
}


/*
void disp_temp(void){
int disp = temp*1024;
disp = disp/3.3; //make sure float after


}
*/
