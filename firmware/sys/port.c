//port.c
#include "sys/port.h"


//#ifdef __MSP430_HAS_PORT1_R__
Port PORT[] = {
	{(byte *)_PINA,(byte *)_PORTA,(byte *)_DDRA},
	{(byte *)_PINB,(byte *)_PORTB,(byte *)_DDRB},
	{(byte *)_PINC,(byte *)_PORTC,(byte *)_DDRC},
	{(byte *)_PIND,(byte *)_PORTD,(byte *)_DDRD},
#ifdef _PORTE
	 {(byte *)_PINE,(byte *)_PORTE,(byte *)_DDRE},
#endif
#ifdef _PORTF
 {(byte *)_PINF,(byte *)_PORTF,(byte *)_DDRF}
#endif
};

Pin PA_PIN[] = {
	{0,PA,b0},
	{1,PA,b1},
	{2,PA,b2},
	{3,PA,b3},
	{4,PA,b4},
	{5,PA,b5},
	{6,PA,b6},
	{7,PA,b7}
};
Pin PB_PIN[] = {
	{0,PB,b0},
	{1,PB,b1},
	{2,PB,b2},
	{3,PB,b3},
	{4,PB,b4},
	{5,PB,b5},
	{6,PB,b6},
	{7,PB,b7}
};
Pin PC_PIN[] = {
	{0,PC,b0},
	{1,PC,b1},
	{2,PC,b2},
	{3,PC,b3},
	{4,PC,b4},
	{5,PC,b5},
	{6,PC,b6},
	{7,PC,b7}
};
Pin PD_PIN[] = {
	{0,PD,b0},
	{1,PD,b1},
	{2,PD,b2},
	{3,PD,b3},
	{4,PD,b4},
	{5,PD,b5},
	{6,PD,b6},
	{7,PD,b7}
};
#ifdef _PORTE
Pin PE_PIN[] = {
	{0,PE,b0},
	{1,PE,b1},
	{2,PE,b2},
	{3,PE,b3},
	{4,PE,b4},
	{5,PE,b5},
	{6,PE,b6},
	{7,PE,b7}
};
#endif
#ifdef _PORTF
Pin PF_PIN[] = {
	{0,PF,b0},
	{1,PF,b1},
	{2,PF,b2},
	{3,PF,b3},
	{4,PF,b4},
	{5,PF,b5},
	{6,PF,b6},
	{7,PF,b7}
};
#endif

//PORT UTILS

void port_config_out( Port *port){
	*port->dir = 0xff;
	*port->out = 0x00;
//	*obj.adr = 0x01;
//	*obj.ctl = 0x00;//output
//	*obj.adr = 0x00;
}

void port_low(Port *port){
	*port->out = 0x00;
}

void port_out_toggle( Port *port){
	*port->out = *port->out ^ 0xff;

}

void port_set( Port *port, byte var){
	*port->out = var;
}


/*
void port_config_in(port obj){
	*(obj.out) = 0x00;
	*(obj.adr) = 0x01;
	*(obj.ctl) = 0xFF;//input
	*(obj.adr) = 0x00;
}


void port_config_alt(port obj){
	*(obj.out) = 0x00;
	*(obj.adr) = 0x02;
	*(obj.ctl) = 0xFF;//output
	*(obj.adr) = 0x00;
}


byte port_get(port obj){
	return *(obj.in);
}

*/


//PIN UTILS
Pin pin_new(  Port *port_ptr, byte id){
	Pin pin = {id,port_ptr, (0x01<<id)};
/*	pin.id = id;
	pin.port_ptr = port_ptr;
	pin.mask = (0x01<<id);
*/	return pin;
}

byte pin_get(Pin *pin){
	byte in;
	in = *pin->port_ptr->in;
	in = in >> pin->id;
	in &= 0x01;
	return in;
}


void pin_set(Pin *pin, byte var){
	if(var)
	pin_high(pin);
	else
	pin_low(pin);
}

void pin_high(Pin *pin){
		*pin->port_ptr->out |= pin->mask;
}

void pin_low(Pin *pin){
		*pin->port_ptr->out &= ~pin->mask;
}


void pin_pulse(Pin *pin){
	delay_ms(1000);
	pin_toggle(pin);
	delay_ms(1000);
	pin_toggle(pin);
	delay_ms(1000);
}

void pin_toggle( Pin *pin){
		*pin->port_ptr->out ^= pin->mask;
}


void pin_config_out(Pin *pin){
	pin_low(pin);
	*pin->port_ptr->dir |= pin->mask;
}

void pin_config_in(Pin *pin){
	pin_low(pin);
	*pin->port_ptr->dir &= ~pin->mask;
}

/*
void pin_config_alt(Pin *pin){
	pin_low(pin);
	*pin->port_ptr->sel |= pin->mask;
}
*/
