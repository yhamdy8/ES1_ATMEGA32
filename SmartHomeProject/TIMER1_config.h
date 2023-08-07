/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: TIMER						***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/



#ifndef  TIMER_1_CONFIG_H_
#define  TIMER_1_CONFIG_H_

/*	TIMER_COUNTER_1_MODE_OF_OPERATION OPTIONS :
 * 												1- TIMER_COUNTER_1_NORMAL_MODE
 * 												2- TIMER_COUNTER_1_PWM_PHASE_CORRECT_MODE
 * 												3- TIMER_COUNTER_1_COMAPRE_MATCH_MODE
 * 												4- TIMER_COUNTER_1_PWM_FAST
 */
#define TIMER_COUNTER_1_MODE_OF_OPERATION	TIMER_COUNTER_1_PWM_FAST


#if TIMER_COUNTER_1_MODE_OF_OPERATION == TIMER_COUNTER_1_COMAPRE_MATCH_MODE

/*	OUTPUT_COMPARE_PIN_OC1_MODE OPTIONS :
 * 												1- OC1_DISABLED
 * 												2- TOGGLE_OC1_ON_CM
 * 												3- CLEAR_OC1_ON_CM
 * 												4- SET_OC1_ON_CM
 */
#define OUTPUT_COMPARE_PIN_OC1_MODE 	OC1_DISABLED

#define TIMER_1_COMP_MATCH_VALUE		125


#elif TIMER_COUNTER_1_MODE_OF_OPERATION == TIMER_COUNTER_1_PWM_FAST

/*	OUTPUT_COMPARE_PIN_OC1_MODE OPTIONS :
 * 												1- OC1_DISABLED
 * 												3- CLR_OC1_ON_COMP_SET_OC1_ON_TOP	// Non-Inverted Mode //
 * 												4- SET_OC1_ON_COMP_CLR_OC1_ON_TOP	// Inverted Mode //
 */
#define OUTPUT_COMPARE_PIN_OC1_MODE		CLR_OC1_ON_COMP_SET_OC1_ON_TOP

#define TIMER_1_COMP_MATCH_VALUE	64

#endif

/*	TIMER_COUNTER_1_PRESCALER OPTIONS :
 * 										1- TIMER_COUNTER_1_DISABLE
* 										2- SYSTEM_CLOCK
* 										3- SC_DIV_BY_8
* 										4- SC_DIV_BY_64
* 										5- SC_DIV_BY_256
* 										6- SC_DIV_BY_1024
* 										7- EXTR_CLK_T0_FALLING_EDGE
* 										8- EXTR_CLK_T0_RISING_EDGE
 */
//#define TIMER_COUNTER_0_PRESCALER	SC_DIV_BY_8
#define TIMER_COUNTER_1_PRESCALER	SC_DIV_BY_8


#endif
