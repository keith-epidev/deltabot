#ifndef I2C_H
#define I2C_H

#include "sys/port.h"
#include "lib/buffer/CircularBuffer.h"
#include "lib/serial/serial.h"

typedef struct I2C{
	Serial serial;
	CircularBuffer buffer;
}I2C;


I2C i2c_master_new(Pin *clk,Pin *rx, Pin *tx);
void i2c_master_put(I2C *i2c, char *c);


#endif
