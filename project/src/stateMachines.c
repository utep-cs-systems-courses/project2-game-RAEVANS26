 #include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"

unsigned char led_toggle_state=0;
unsigned char power_off_state=0;
char toggle_led()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    green_on=0;
    state = 1;
    break;
  case 1:
    red_on = 0;
    green_on=1;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char led_Off()	/* only toggle green if red is on!  */
{
    green_on = 0;
    red_on=0;
  return 1;
}

void state_update()
{
    if(sw1_down){
        led_toggle_state=1;
        power_off_state=0;
    }
     else if(sw4_down){
        led_toggle_state=0;
        power_off_state=1;
    }
}
void light_toggle()		/* alternate between toggling red & green */
{
  char changed = 0;
  changed = toggle_led(); 
  led_changed = changed;
  led_update();
}

void power_off()
{
  char changed = 0;
  changed = led_Off();
  led_changed = 1;
  led_update();
}

