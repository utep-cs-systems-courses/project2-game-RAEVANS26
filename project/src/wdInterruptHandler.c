#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 125) {
    ///state_advance();// add cases with functions from statemachines
    if(power_off_state){
        power_off();
    }
    if(led_toggle_state){
        light_toggle();
    }
    blink_count = 0;
  }
}
