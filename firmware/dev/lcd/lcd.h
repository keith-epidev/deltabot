#ifndef LCD_H
#define LCD_H

#include "sys/port.h"
#include "lib/serial/serial.h"
#include "lib/delay/delay.h"

typedef struct LCD{
	Spi *spi;
	int col;
	int row;
	int cursor;
	Pin *rst;
	Pin *mode;
	Pin *enb;
	CircularBuffer *buffer;
}LCD;

/*
typedef struct LCD{
	Port *data;	//	Serial serial;
	Pin *RS;
	Pin *RW;
	Pin *E;
	int col;
	int row;
}LCD;
*/
//LCD lcd_new(Pin *clk, Pin *data, Pin *mode, Pin *reset);
//void write_string(LCD *lcd,char *s);
//void write_character(LCD *lcd,char c);

//void shift_register_latch_output(Shift_register *shift_register);


#endif
