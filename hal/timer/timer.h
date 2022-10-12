/*
 * timer.h
 *
 * Created: 12/10/2022 12:21:01
 *  Author: Ruben
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "compiler.h"


typedef void (*timer_cb_t)(void);

typedef enum {
	TIMER_ONE_SHOT_MODE,		//!< Timer execute until expired
	TIMER_REPEAT_MODE			//!< Timer execute automatically when expired
} timer_mode_t;


struct timer_struct {
	uint8_t					timer_interval;
	uint8_t					timer_counter;
	uint8_t					number_timer;
	timer_mode_t			timer_mode;
	timer_cb_t 				timer_callback;
	struct timer_struct*	timer_next;	
};


uint8_t TCA_init(void);


#endif /* TIMER_H_ */