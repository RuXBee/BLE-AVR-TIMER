/*
 * AVR-BLE-TIMER.c
 *
 * Created: 10/10/2022 18:02:30
 * Author : Ruben
 */ 

#define F_CPU	2000000UL

#include "compiler.h"


int main(void)
{
	SYS_CLK_init();
	
	TURN_ON_LED(LED_DATA_GREEN_PORT ,LED_DATA_GREEN_PIN_bm);
    
	/* Infinite loop */
    while (1) 
    {
    }
}

