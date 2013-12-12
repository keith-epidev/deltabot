#include "etc/byte.h"
#include "etc/config.h"
#include "dev/stepper/stepper.h"
#include "lib/position/position.h"
#include "sys/port.h"
#include "sys/console.h"
#include "dev/uart/uart.h"
//#include "dev/thermistor/thermistor.h"

#include <util/delay.h>
#include <avr/interrupt.h> 


int main(void){

	pin_config_out(g_led);
	pin_config_out(r_led);
	pin_config_out(e_heat);
	pin_config_out(b_heat);
	pin_config_out(buzzer);

	pin_config_in(x_stop);
	pin_config_in(y_stop);
	pin_config_in(z_stop);
	pin_config_in(sense_rx);

	pin_high(e_heat);
	pin_high(b_heat);

	stepper_init(x_step,x_dir,motor_enb);
	stepper_init(y_step,y_dir,motor_enb);
	stepper_init(z_step,z_dir,motor_enb);
	stepper_start_frame();
	steppers_disable();


	uart_init();
	console_init();
//	thermistor_init();
	console_prompt();
}


