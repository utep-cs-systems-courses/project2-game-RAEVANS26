#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

//char switch_state_down, switch_state_changed; /* effectively boolean */
char sw1_down, sw1_changed,
    sw2_down, sw2_changed,
    sw3_down, sw3_changed,
    sw4_down, sw4_changed;

// static char 
// switch_update_interrupt_sense()
// {
//   char p1val = P1IN;
//   /* update switch interrupt to detect changes from current buttons */
//   P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
//   P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
//   return p1val;
// }

static char 
switch1_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SW1);	/* if switch up, sense down */
  P2IES &= (p2val | ~SW1);	/* if switch down, sense up */
  return p2val;
}
static char 
switch2_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SW2);	/* if switch up, sense down */
  P2IES &= (p2val | ~SW2);	/* if switch down, sense up */
  return p2val;
}
static char 
switch3_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SW3);	/* if switch up, sense down */
  P2IES &= (p2val | ~SW3);	/* if switch down, sense up */
  return p2val;
}
static char 
switch4_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SW4);	/* if switch up, sense down */
  P2IES &= (p2val | ~SW4);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch1_update_interrupt_sense();
  switch2_update_interrupt_sense();
  switch3_update_interrupt_sense();
  switch4_update_interrupt_sense();
  led_update();
}

void
switch1_interrupt_handler()
{
  char p2val = switch1_update_interrupt_sense();
  sw1_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  sw1_changed = 1;
  state_update();//include in statemachine.h and .c
  led_update();
}
void
switch2_interrupt_handler()
{
  char p2val = switch2_update_interrupt_sense();
  sw2_down = (p2val & SW2) ? 0 : 1; /* 0 when SW1 is up */
  sw2_changed = 1;
  //state_update();//include in statemachine.h and .c
  led_update();
}
void
switch3_interrupt_handler()
{
  char p2val = switch3_update_interrupt_sense();
  sw3_down = (p2val & SW3) ? 0 : 1; /* 0 when SW1 is up */
  sw3_changed = 1;
  //state_update();//include in statemachine.h and .c
  led_update();
}
void
switch4_interrupt_handler()
{
  char p2val = switch4_update_interrupt_sense();
  sw4_down = (p2val & SW4) ? 0 : 1; /* 0 when SW1 is up */
  sw4_changed = 1;
  state_update();//include in statemachine.h and .c
  led_update();
}
