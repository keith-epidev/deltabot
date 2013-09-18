OBJS=main/serial.c sys/port.c lib/delay/delay.c dev/uart/uart.c lib/buffer/CircularBuffer.c dev/stepper/stepper.c
#OBJS=main/step.c sys/port.c lib/delay/delay.c dev/stepper/stepper.c
#main/rec.c
#main/serial.c sys/port.c lib/delay/delay.c lib/serial/serial.c dev/uart/uart.c lib/buffer/CircularBuffer.c
#main/inter.c sys/port.c lib/delay/delay.c
#main/serial.c dev/uart/uart.c sys/port.c lib/delay/delay.c lib/buffer/CircularBuffer.c
#main/lcd.c sys/port.c lib/delay/delay.c dev/lcd/3310/3310.c lib/serial/serial.c
CC=msp430-gcc
#CFLAGS=  -std=gnu99 -Os -Wall -g -mmcu=msp430g2553 -mdisable-watchdog # right one
CFLAGS=  -std=gnu99 -Os -Wall -g -mmcu=msp430g2452  -mdisable-watchdog  # left ones
#-mmcu=msp430g2452 # left ones
#-mmcu=msp430g2553
all: $(OBJS)
#	$(CC) $(CFLAGS)  $(OBJS) -I ./
	$(CC) $(CFLAGS) -o compiled.elf $(OBJS) -I ./

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr compiled.elf

prog:
	mspdebug rf2500 'prog compiled.elf'
