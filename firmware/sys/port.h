#ifndef PORT_H
#define PORT_H

#include <avr/io.h>
#include "etc/byte.h"
#include "lib/delay/delay.h"
#include "etc/config.h"


typedef volatile uint8_t vbyte;

typedef struct Port{
        vbyte  *in;
        vbyte  *out;
        vbyte  *dir;
//        byte *ifg;
//        byte *ies;
 //       byte *ie;
//        byte *sel;
  //      byte *ren;
}Port;

typedef struct Pin{
	byte id;	
	Port *port_ptr;
        byte mask;
}Pin;


extern Port PORT[];
#define PA &PORT[0]
#define PB &PORT[1]
#define PC &PORT[2]
#define PD &PORT[3]
extern Pin PA_PIN[];
#define PA0 &PA_PIN[0]
#define PA1 &PA_PIN[1]
#define PA2 &PA_PIN[2]
#define PA3 &PA_PIN[3]
#define PA4 &PA_PIN[4]
#define PA5 &PA_PIN[5]
#define PA6 &PA_PIN[6]
#define PA7 &PA_PIN[7]
extern Pin PB_PIN[];
#define PB0 &PB_PIN[0]
#define PB1 &PB_PIN[1]
#define PB2 &PB_PIN[2]
#define PB3 &PB_PIN[3]
#define PB4 &PB_PIN[4]
#define PB5 &PB_PIN[5]
#define PB6 &PB_PIN[6]
#define PB7 &PB_PIN[7]
extern Pin PC_PIN[];
#define PC0 &PC_PIN[0]
#define PC1 &PC_PIN[1]
#define PC2 &PC_PIN[2]
#define PC3 &PC_PIN[3]
#define PC4 &PC_PIN[4]
#define PC5 &PC_PIN[5]
#define PC6 &PC_PIN[6]
#define PC7 &PC_PIN[7]
extern Pin PD_PIN[];
#define PD0 &PD_PIN[0]
#define PD1 &PD_PIN[1]
#define PD2 &PD_PIN[2]
#define PD3 &PD_PIN[3]
#define PD4 &PD_PIN[4]
#define PD5 &PD_PIN[5]
#define PD6 &PD_PIN[6]
#define PD7 &PD_PIN[7]


#ifdef PORTE
#define PE &PORT[4]
#define PE0 &PE_PIN[0]
#define PE1 &PE_PIN[1]
#define PE2 &PE_PIN[2]
#define PE3 &PE_PIN[3]
#define PE4 &PE_PIN[4]
#define PE5 &PE_PIN[5]
#define PE6 &PE_PIN[6]
#define PE7 &PE_PIN[7]
#endif

#ifdef PORTF
#define PF &PORT[5]
#define PF0 &PF_PIN[0]
#define PF1 &PF_PIN[1]
#define PF2 &PF_PIN[2]
#define PF3 &PF_PIN[3]
#define PF4 &PF_PIN[4]
#define PF5 &PF_PIN[5]
#define PF6 &PF_PIN[6]
#define PF7 &PF_PIN[7]
#endif

//port functions
void port_config_out(Port *port);
void port_out_toggle(Port *port);
void port_low(Port *port);
void port_high(Port *port);
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

