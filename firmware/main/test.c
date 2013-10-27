#include "etc/byte.h"
#include "etc/config.h"
#include "dev/stepper/stepper.h"
#include "sys/port.h"
#include "sys/console.h"
#include "dev/uart/uart.h"
#include "dev/thermistor/thermistor.h"


#include <util/delay.h>
#include <avr/interrupt.h> 


int main(void){

	pin_config_out(g_led);
	pin_config_out(r_led);
	pin_config_out(e_heat);
	pin_config_out(b_heat);
	pin_config_out(buzzer);
	pin_low(buzzer);


	Stepper *stepper_x = stepper_init(x_step,x_dir,motor_enb);
	Stepper *stepper_y = stepper_init(y_step,y_dir,motor_enb);
	Stepper *stepper_z = stepper_init(e_step,e_dir,motor_enb);
//	stepper_start_frame();

	Uart *uart = uart_init();
	console_init();
	thermistor_init();
//	console_prompt();

	pin_config_in(x_stop);

	pin_high(r_led);

	char dir = 1;
	int count = 0;
	unsigned int hit = 0;	

	while(1){

//		dir = pin_get(EXP2);
		stepper_dir(stepper_x,dir);
		stepper_dir(stepper_y,dir);
		stepper_dir(stepper_z,dir);

		if(dir == 1)
		if(pin_get(x_stop)==0 ){
			if(hit < 2){
			stepper_step(stepper_x);
			stepper_step(stepper_y);
			stepper_step(stepper_z);
			count++;
			}
		}else{
			hit++;
			if(hit < 2){
			printf("%i\n",count);
			printf("HIT!\n");
			dir = 0;
			hit = 0;
			} 
		}
		



		if(dir == 0){
			stepper_step(stepper_x);
			stepper_step(stepper_y);
			stepper_step(stepper_z);
			count--;
			if(count == 0){
			dir = 1;
			}
		}








			_delay_us(10);

/*
			count++;
			if(count == 1000){
				pin_toggle(g_led);
				count = 0;
			//	pin_toggle(stepper_x->direction);
			//	pin_toggle(stepper_y->direction);
			//	pin_toggle(stepper_z->direction);
			}
*/

	}


}


/*
void disp_temp(void){
int disp = temp*1024;
disp = disp/3.3; //make sure float after


}
*/
