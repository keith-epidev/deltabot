#include "etc/byte.h"
#include "etc/config.h"
#include "sys/port.h"
//#include "dev/uart/uart.h"
//#include "dev/thermistor/thermistor.h"


#include <util/delay.h>
#include <avr/interrupt.h> 


int main(void){

	pin_config_out(g_led);
	pin_config_out(r_led);
	pin_config_out(buzzer);
	pin_config_out(y_dir);
	pin_config_out(e_heat);

	pin_config_in(x_stop);

	while(1){

	pin_toggle(g_led);

	_delay_ms(1000);


	pin_toggle(r_led);
	_delay_ms(1000);

	}
	return 1;
}

/*
void disp_temp(void){
int disp = temp*1024;
disp = disp/3.3; //make sure float after


}
*/
