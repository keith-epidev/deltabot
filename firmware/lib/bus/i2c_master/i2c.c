#include "i2c.h"


I2C i2c_master_new(Pin *clk,Pin *tx, Pin *rx){
	I2C temp = {{clk,tx},circular_buffer_new(16)};
		pin_config_out(clk);
		pin_config_out(rx);
		pin_config_out(tx);


	return temp;
}





void i2c_master_put(I2C *i2c, char *c){
		serial_out(&i2c->serial,'t');
		serial_out(&i2c->serial,c[0]);
		serial_out(&i2c->serial,c[1]);


}






