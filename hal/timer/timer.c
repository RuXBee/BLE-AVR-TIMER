/*
 * timer.c
 *
 * Created: 12/10/2022 12:21:12
 *  Author: Ruben
 */ 
#include "timer.h"
#include "leds.h"

static uint16_t counter;

static void (*timer_tca0_callback)(void) = NULL;

static void timer_tca0_cb(void) {
	
	counter++;
		
	if ((counter % 1000) == 0){
		counter = 0;
		led_toggle(LED_GREEN);
	}
}

uint8_t TCA_init(void) {
	uint8_t val;
	
	// Disable Timer
	ccp_write_io((void *)&(TCA0.SPLIT.CTRLA), 
				 ~TCA_SPLIT_ENABLE_bm);
	
	// Hard reset to avoid unexpected behavior
	ccp_write_io((void *)&(TCA0.SPLIT.CTRLESET),
				 TCA_SPLIT_CMD_RESET_gc);
	
	// Enable split mode
	TCA0.SPLIT.CTRLD |= TCA_SPLIT_SPLITM_bm;
	
	// Write TOP value to the Period register
	TCA0.SPLIT.HPER = 32;
	TCA0.SPLIT.HCNT = TCA0.SPLIT.HPER;
	
	// Enable interrupt underflow
	TCA0.SPLIT.INTCTRL |= TCA_SPLIT_HUNF_bm;
	
	// Every 1mS. Enable peripheral and set clock (main clock 2MHz)
	val = TCA_SPLIT_ENABLE_bm | TCA_SPLIT_CLKSEL_2_bm | TCA_SPLIT_CLKSEL_0_bm;
	ccp_write_io((void*)&(TCA0.SPLIT.CTRLA),
				 val);
	
	// Register callback
	timer_tca0_callback = timer_tca0_cb;
	return 1;
	
}



ISR(TCA0_HUNF_vect) {
	TCA0.SPLIT.INTFLAGS |= TCA_SPLIT_HUNF_bm;
	
	if (timer_tca0_callback != NULL) {
		timer_tca0_callback();
	}
}