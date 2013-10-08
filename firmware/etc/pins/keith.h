#ifndef PINS_H
#define PINS_H

#include "sys/port.h"


//#define PA0
//#define PA1
#define bed_thermistor PA2
#define extr_thermistor PA3
#define extr_dir PA4
#define z_dir PA5
#define y_dir PA6
#define x_dir PA7

#define fault PB0
#define SCLK PB1
#define MOSI PB2
#define MISO PB3
#define extr_temp PB4
#define CS3 PB5
#define extr_step PB6
#define bed_temp PB7

#define LED_G PC0
#define LED_O PC1
#define LED_R PC2
#define MOSFET3 PC3
#define x_step PC4
#define y_step PC5
#define z_step PC6
#define MOSFET2 PC7

#define SCL PD0
#define SDA PD1
#define ROT1 PD2
#define ROT2 PD3
#define ROT3 PD4
#define CS2 PD5
#define CS1 PD6
#define buzzer PD7

#define MOSFET1 PE0
//#define PE1
#define MOSFET4 PE2
#define UID PE3
#define z_endstop PE4
#define extr_endstop PE5
#define x_endstop PE6
#define y_endstop PE7

#define EXP4 PF0
#define EXP3 PF1
#define EXP1 PF2
#define EXP2 PF3
#define TCK PF4
#define TMS PF5
#define TDO PF6
#define TDI PF7

#endif

