#include <msp430.h>
#include "etc/byte.h"
#include "sys/port.h"
#include "dev/uart/uart.h"

#define speed 100000

int main(void){
	WDTCTL = WDTPW + WDTHOLD;	// Stop WDT


	Pin P1_4 = pin_new(&P1,4);	//TXD
	Pin P1_5 = pin_new(&P1,5);	//RXD
	
	Uart *uart = uart_init(&P1_4,&P1_5);

	uart_putstr(uart,"\0\0\0\0\r\n");
	__delay_cycles (speed);
	__delay_cycles (speed);
	uart_putstr(uart,"UART init\r\n");
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);
	uart_putstr(uart,"Spamming:\r\n");
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);
	__delay_cycles (speed);

	while(1){
		//1st chip on

	uart_put(uart,'a');
	__delay_cycles (speed);
	uart_put(uart,'b');
	__delay_cycles (speed);
	uart_put(uart,'c');
	__delay_cycles (speed);
	uart_put(uart,' ');
	__delay_cycles (speed);
	
	__delay_cycles (speed);
	uart_putstr(uart,"String \r\n");
	__delay_cycles (speed);
	uart_putstr(uart,"\r\n");
	__delay_cycles (speed);
	}

	return 1;
}
