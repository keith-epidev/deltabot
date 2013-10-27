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
	Stepper *stepper_z = stepper_init(z_step,z_dir,motor_enb);
	stepper_start_frame();

	Uart *uart = uart_init();
	console_init();
	thermistor_init();
	console_prompt();


}


/*
void disp_temp(void){
int disp = temp*1024;
disp = disp/3.3; //make sure float after


}
*/
