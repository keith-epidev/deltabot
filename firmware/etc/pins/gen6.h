#ifndef PINS_H
#define PINS_H

#include "sys/port.h"


#define x_enable PA0
#define z_end_stop PA1
#define z_enable PA2
#define z_dir PA3
#define z_step PA4
#define thermistor PA5
#define y_end_stop PA6
#define y_enable PA7

//#define end_stop_z PB0
//#define z_end_stop PB1
#define e_dir PB2
#define e_enable PB3
#define e_step PB4
#define MOSI PB5
#define MISO PB6
#define SCK PB7

#define x_dir PD3
#define SCL PC0
#define SDA PC1
//#define x_dir PC2
//#define x_enable PC3
#define x_end_stop PC4
//#define  PC5
#define y_dir PC6
#define y_step PC7

#define RXD PD0
#define TXD PD1
#define RS485_R PD2
#define RS485_D PD3
#define RS485_DE PD4
#define RS485_RE PD5
#define heat PD6
#define x_step PD7




#endif 
