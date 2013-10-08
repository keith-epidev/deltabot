#include "etc/byte.h"
#include "etc/config.h"
#include "sys/port.h"
#include "dev/stepper/stepper.h"
#include <util/delay.h>


int main(void){

Stepper *stepper_e = stepper_init(e_step,e_dir,e_enable);
//Stepper *stepper_x = stepper_init(x_step,x_dir,x_enable);
Stepper *stepper_y = stepper_init(y_step,y_dir,y_enable);

Stepper *stepper_z = stepper_init(z_step,z_dir,z_enable);
stepper_start_frame();

while(1);



//	Pin PD_0 = pin_new(&P[3],0);
//	pin_config_out(&PD_0);
//	pin_low(&PD_0);
/*
	while(1){
	pin_low(&PD_0);
	delay_ms(100000);
	}
*/
	return 1;
}
