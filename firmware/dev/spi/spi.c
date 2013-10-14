#include "spi.h"
#include "etc/config.h"
#include <avr/interrupt.h>
#include "sys/console.h"
#include <util/delay.h>

volatile char value;
Spi *spi_target;
/*
ISR(USART0_RX_vect){
	value = UDR0;             //read UART register into value
	if(value == '\r')
	value = '\0';

	circular_buffer_put(spi_target->in,value);
	uart_put(value);//echo
	
	if(value == '\0'){
		uart_write("\r\n");
		spi_target->new_line = 1;
	}
}
*/




ISR(SPI_STC_vect){
	value = SPDR; //received

	if(!circular_buffer_isempty(spi_target->out)){
		SPDR = circular_buffer_get(spi_target->out);
	}else
	spi_target->cts = 1;


}

Spi* spi_init(){
	Spi *spi = (Spi * ) malloc( sizeof( Spi ) );
	spi->in = circular_buffer_new(16);
	spi->out = circular_buffer_new(16);
	spi->cts = 1;

	pin_config_out(MOSI);
	pin_config_out(SCLK);
	pin_config_in(MISO);
	pin_config_out(SS);	// for some reason must be kept as an output

	SPCR |= (1<<MSTR);              // Set as Master
	SPCR |= (1<<SPR0)|(1<<SPR1);    // divided clock by 128
	SPCR |= (1<<SPIE);		//Enable Interupt
	SPCR |= (1<<SPE);               // Enable SPI

	spi_target = spi;
	return spi;
}


/*
void uart_get(void){
	spi_target->new_line = 0;
}
void uart_write(char *data){

	circular_buffer_putstr(spi_target->out,data);


	if((UCSR0A &(1<<UDRE0)) != 0)
	UDR0 = circular_buffer_get(spi_target->out);

}

char uart_new_line(){
	return spi_target->new_line;
}
*/

void spi_put(char data){
	circular_buffer_put(spi_target->out,data);

	if(spi_target->cts){
		spi_target->cts = 0;
		SPDR = circular_buffer_get(spi_target->out);
	}
}





/*
void uart_put_printf(char data, FILE *stream) {
    if (data == '\n') uart_put('\r'); //new line for linux term
    uart_put(data);
}

      // Wait until a byte has been received and return received data 
byte uart_read(){
	while((UCSR0A &(1<<RXC0)) == 0);
	return UDR0;
}
*/
