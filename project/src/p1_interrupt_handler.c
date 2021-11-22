#include <msp430.h>
#include "switches.h"

/* Switches on P2  */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SW1) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SW1;		      /* clear pending sw interrupts */
    switch1_interrupt_handler();	/* single handler for all switches */
  }
  if (P2IFG & SW2) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SW2;		      /* clear pending sw interrupts */
    switch2_interrupt_handler();	/* single handler for all switches */
  }
  if (P2IFG & SW3) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SW3;		      /* clear pending sw interrupts */
    switch3_interrupt_handler();	/* single handler for all switches */
  }
  if (P2IFG & SW4) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SW4;		      /* clear pending sw interrupts */
    switch4_interrupt_handler();	/* single handler for all switches */
  }
}

