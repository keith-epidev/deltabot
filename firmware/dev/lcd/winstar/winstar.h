#ifndef LCDWINSTAR_H
#define LCDWINSTAR_H

#include "sys/port.h"
#include "dev/serial/serial.h"
#include "lib/delay/delay.h"
#include "dev/lcd/lcd.h"



LCD lcd_new(Port *data, Pin *RS, Pin *RW, Pin *E);
void write_string(LCD *lcd,char *s);
void write_character(LCD *lcd,char c);

//void shift_register_latch_output(Shift_register *shift_register);


#endif
