#ifndef switches_included
#define switches_included

//#define SW1 BIT3		/* switch1 is p1.3 */
//#define SWITCHES SW1		/* only 1 switch on this board */

#define SW1 BIT0		/* switch1 is p1.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1|SW2|SW3|SW4)

void switch_init();
void switch1_interrupt_handler();
void switch2_interrupt_handler();
void switch3_interrupt_handler();
void switch4_interrupt_handler();

//extern char switch_state_down, switch_state_changed; /* effectively boolean */

extern char sw1_down, sw1_changed, 
    sw2_down, sw2_changed,
    sw3_down, sw3_changed,
    sw4_down, sw4_changed;
#endif // included
