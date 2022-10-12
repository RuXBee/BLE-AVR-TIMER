/*
 * AVR-BLE-TIMER.c
 *
 * Created: 10/10/2022 18:02:30
 * Author : Ruben
 */ 

#define F_CPU	2000000UL

#include "compiler.h"

static void sys_drivers_init(void) {
	
	cli();
	// Initialize oscillator and system clock
	SYS_CLK_init();
	
	// Intialize timer TCA0 as split mode
	TCA_init();
	
	sei();
	
}



int main(void) {
	
	// Initialize system and drivers
	sys_drivers_init();
	
    
	/* Infinite loop */
    while (1) {
    
	}
}

