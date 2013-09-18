#include <msp430.h>
#include "etc/byte.h"
#include "sys/port.h"
#include "dev/uart/uart.h"
#include "dev/stepper/stepper.h"
//#include "lib/bus/i2c_master/i2c.h"


int main(void){
	WDTCTL = WDTPW + WDTHOLD;	// Stop WDT


	Pin P1_0 = pin_new(&P1,0);	//CLK
	Pin P1_1 = pin_new(&P1,1);	//TXD
	Pin P1_2 = pin_new(&P1,2);	//RXD

	Pin P1_7 = pin_new(&P1,7);	//LED
	pin_config_out(&P1_7);
	
	Uart *uart = uart_init(&P1_1,&P1_2);
	Stepper *stepper = stepper_init(&P2);

	char address = 0;
	char command = 0;
	char temp = 0;
	int stage = 0;

	while(1){

		temp = uart_receive();
		if(temp != '\n'){
			if(stage == 0)
			address = temp;
			else
			command = temp;
			stage++;
		}
		else{
			stage = 0;

			if(address == '1')
			switch(command){
			case '1':
				stepper_step(stepper);
				break;
			case '2':
				pin_low(&P1_7);
				stepper_dir(stepper,0);
				break;
			case '3':
				pin_high(&P1_7);
				stepper_dir(stepper,1);
				break;
			default:
				break;
			}
		}
	}



	return 1;
}


/*
void print_menu(Uart *uart) {
      uart_putstr(uart,"Welcome\r\n");
		__delay_cycles (100000);
      uart_putstr(uart,"Hey!\r\n");
		__delay_cycles (100000);
      uart_putstr(uart,"Display\r\n");
		__delay_cycles (100000);
      //uart_putstr(uart,"2. Show current temperature\r\n");
      //uart_putstr(uart,"3. Display EEPROM data\r\n\n");
}
 */
/**
 * Executes the action depending on the user choice
 */
/*
void execute_action( Uart *uart, char choice ) {
      switch (choice) {
            case '1': {
		
                  uart_putstr(uart,"Done\r\n\n");
             //     uart_putstr(uart,"Welcome to the world of micro-controllers.. \r\n\n");
            } break;
           
            case '2' : {
                  //read temperature     
            } break;
           
            case '3' : {
                  //display eeprom data
            } break;
      }
}

*/
