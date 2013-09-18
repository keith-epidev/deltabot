#ifndef I2C_H
#define I2C_H

#include "sys/port.h"
#include "dev/serial/serial.h"
#include "lib/delay/delay.h"
#include "dev/lcd/winstar/winstar.h"

typedef struct Display{
	LCD *lcd;
	char *buffer;
	int pointer;
}Display;




Display display_new(LCD *lcd);
void display_print(Display *display,char *string);
void display_commit(Display *display);

#endif
