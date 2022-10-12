/*
 * leds.h
 *
 * Created: 12/10/2022 12:14:55
 *  Author: Ruben
 */ 


#ifndef LEDS_H_
#define LEDS_H_

#include "compiler.h"


typedef enum {
	LED_GREEN,
	LED_RED	
} led_color_t;

typedef enum {
	LED_ON,
	LED_OFF,
	LED_TOGGLE	
} led_operation_t;

static inline void led_toggle(led_color_t led) {
	
	switch (led)
	{
	case LED_GREEN:
		LED_DATA_GREEN_PORT.DIRSET = LED_DATA_GREEN_PIN_bm;
		LED_DATA_GREEN_PORT.OUTTGL = LED_DATA_GREEN_PIN_bm;
		break;
	
	case LED_RED:
		break;
			
	default:
		break;
	}
}

#endif /* LEDS_H_ */