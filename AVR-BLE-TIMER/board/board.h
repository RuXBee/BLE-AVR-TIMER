/*
 * board.h
 *
 * Created: 10/10/2022 19:42:10
 *  Author: Ruben
 */ 


#ifndef BOARD_H_
#define BOARD_H_


#define LED_DATA_GREEN_PORT		PORTF
#define LED_DATA_GREEN_PIN_bm	PIN4_bm

#define SW_USER_PORT			PORTF
#define SW_USER_PIN_bm			PIN3_bm
#define SW_USER_CTRL			NULL


/* Define rapid functions */
#define TURN_ON_LED(PORT, PIN) do {	\
	LED_DATA_GREEN_PORT.DIRSET = PIN;	\
	LED_DATA_GREEN_PORT.OUTCLR = PIN;	\
} while (0);

#define TURN_OFF_LED(PORT, PIN) do {	\
	PORT.DIRSET = PIN;	\
	PORT.OUTSET = PIN;	\
} while (0);



#endif /* BOARD_H_ */