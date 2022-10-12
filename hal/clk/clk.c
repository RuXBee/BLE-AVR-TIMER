/*
 * clk.c
 *
 * Created: 10/10/2022 18:04:03
 *  Author: Ruben
 */ 

#include "clk.h"


uint8_t SYS_CLK_init(void) {
	uint8_t retries = 0;
	
	// Enable 20MHz main clock and system clock out
	ccp_write_io((void*)&(CLKCTRL.MCLKCTRLA), 
				 CLKCTRL_CLKOUT_bm | CLKCTRL_CLKSEL_OSC20M_gc);
	
	// Enable preescaler and divided x10
	ccp_write_io((void*)&(CLKCTRL.MCLKCTRLB),
				 CLKCTRL_PDIV_10X_gc | CLKCTRL_PEN_bm); 
	
	// Run standby disabled
	ccp_write_io((void*)&(CLKCTRL.OSC20MCTRLA),
				 (0 << CLKCTRL_RUNSTDBY_bp));
		 
	while (CLKCTRL.MCLKSTATUS & CLKCTRL_OSC20MS_bm) {
		if (retries++ > 10) return 0;
	}
	
	return 1;
	
}