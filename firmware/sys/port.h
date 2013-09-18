#ifndef PORT_H
#define PORT_H

#include <io.h>
#include "etc/byte.h"
#include "lib/delay/delay.h"



typedef const struct Port{
        byte volatile *in;
        byte volatile *out;
        byte volatile *dir;
        byte volatile *ifg;
        byte volatile *ies;
        byte volatile *ie;
        byte volatile *sel;
        byte volatile *ren;
}Port;

typedef const struct Pin{
	byte id;	
        Port *port_ptr;
        byte mask;
}Pin;


extern Port P1;
extern Port P2;


//port functions
void port_config_out(Port *port);
void port_out_toggle(Port *port);
void port_low(Port *port);
void port_set(Port *port, byte var);
//pin functions
Pin pin_new(Port *port_ptr, byte id);
byte pin_get(Pin *pin);
void pin_set(Pin *pin, byte var);
void pin_high(Pin *pin);
void pin_low(Pin *pin);
void pin_config_out(Pin *pin);
void pin_config_in(Pin *pin);
void pin_config_alt(Pin *pin);
void pin_pulse(Pin *pin);
void pin_toggle(Pin *pin);
#endif

