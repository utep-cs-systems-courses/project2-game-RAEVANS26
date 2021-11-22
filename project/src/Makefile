# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf

#additional rules for files
#main.elf: ${COMMON_OBJECTS} main.o led.o buzzer.o switches.o stateMachines.o wdInterruptHandler.o p2_interrupt_handler.o ../lib/libTimer.a
#	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

main.elf: main.o led.o stateMachines.o wdInterruptHandler.o switches.o stateMachines.o p1_interrupt_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

swithces.o: switches.h led.h stateMachines.h

#buzzer.o: buzzer.h

#stateMachines.o: switches.h led.h buzzer.h stateMachines.h
stateMachines.o: led.h stateMachines.h switches.h

wdInterruptHandler.o: stateMachines.h

p1_interrupt_handler.o: switches.h 

#main.o: switches.h led.h buzzer.h
main.o:led.h
