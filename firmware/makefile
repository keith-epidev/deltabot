OBJS=main/uart.c sys/port.c lib/delay/delay.c dev/stepper/stepper.c dev/uart/uart.c lib/buffer/CircularBuffer.c dev/thermistor/thermistor.c dev/spi/spi.c dev/lcd/3310/3310.c sys/console.c lib/position/position.c
CC=avr-gcc
#CFLAGS=  -std=gnu99  -Os -Wall -g -mmcu=at90usb1286
CFLAGS=  -std=gnu99  -Os -Wall -g -mmcu=atmega644p -lm -Wl,-u,vfprintf -lprintf_flt  
all: $(OBJS)
	        $(CC) $(CFLAGS) -o compiled.elf $(OBJS) -I ./
		avr-objcopy -j .text -j .data -O ihex compiled.elf compiled.hex		
%.o: %.c
	        $(CC) $(CFLAGS) -c $<

clean:
	        rm -fr compiled.elf

prog:
#		avrdude -p usb1286 -c dragon_jtag -P usb -B5 -e -U flash:w:compiled.hex
		avrdude -p atmega644p -c dragon_isp -P usb -B5 -e -U flash:w:compiled.hex


