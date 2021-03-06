#include "uart.h"
#include "etc/config.h"
#include <avr/interrupt.h>

// Define baud rate
#define USART_BAUDRATE 38400
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


volatile char value;
Uart *target;

ISR(USART0_RX_vect){
	value = UDR0;             //read UART register into value

	if(value == 127){
	char t = circular_buffer_pop(target->in);
	if(t!=0)uart_write("\b \b");
	return;
	}

	if(value == '\r')
	value = '\0';

	circular_buffer_put(target->in,value);
//	uart_put(value);//echo
	
	if(value == '\0'){
//		uart_write("\r\n");
		target->new_line++;
	}


//	pin_toggle(r_led);
}

ISR(USART0_TX_vect){
	if(!circular_buffer_isempty(target->out))
		UDR0 = circular_buffer_get(target->out);

	pin_toggle(g_led);

}


Uart* uart_init(){

	Uart *uart = (Uart * ) malloc( sizeof( Uart ) );

	uart->in = circular_buffer_new(128);
	uart->out = circular_buffer_new(128);
	uart->new_line = 0;

	UBRR0L = BAUD_PRESCALE;
	UBRR0H = (BAUD_PRESCALE >> 8); 
	UCSR0B = ((1<<TXEN0)|(1<<RXEN0) | (1<<RXCIE0) | (1<<TXCIE0) );


	sei();
	target = uart;

	return uart;;
}


void uart_enable(){
	UCSR0B |= ((1<<TXEN0)|(1<<RXEN0) | (1<<RXCIE0) | (1<<TXCIE0) );

}

void uart_disable(){

	UCSR0B &= ~((1<<TXEN0)|(1<<RXEN0) | (1<<RXCIE0) | (1<<TXCIE0) );
}


char uart_get(void){
	char temp = circular_buffer_get(target->in);
	if(temp == '\n' || temp == 0){
		target->new_line--;
		return 0;
	}else{
	return temp;
	}
}

void uart_write(char *data){

	circular_buffer_putstr(target->out,data);


	if((UCSR0A &(1<<UDRE0)) != 0)
	UDR0 = circular_buffer_get(target->out);

}

char uart_new_line(){
	return target->new_line;
}

void uart_put(char data){

	circular_buffer_put(target->out,data);


	if((UCSR0A &(1<<UDRE0)) != 0)
	UDR0 = circular_buffer_get(target->out);
}

void uart_put_printf(char data, FILE *stream) {
    if (data == '\n') uart_put('\r'); //new line for linux term
    uart_put(data);
}

      // Wait until a byte has been received and return received data 
byte uart_read(){
	while((UCSR0A &(1<<RXC0)) == 0);
	return UDR0;
}

