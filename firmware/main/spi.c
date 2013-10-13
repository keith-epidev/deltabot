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
	LCD *lcd = lcd_new(SDA,SCL,0);


	thermistor_init();

	char temps[64] = {0}; 

	int l = 0;
	while(1){
	gotoXY(lcd,0,0);
	l = sprintf(temps,"temp: %0.2fC°",thermistor_get_c());
	temps[l-1] = 0;
	write_string(lcd,temps);
	printf("ping\n");
	_delay_ms(100);


	}	


	return 1;
}


/*
void disp_temp(void){
int disp = temp*1024;
disp = disp/3.3; //make sure float after


}
*/
