/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: TIMER0						***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/



#ifndef  TIMER_CONFIG_H_
#define  TIMER_CONFIG_H_

/*	TIMER_COUNTER_0_MODE_OF_OPERATION OPTIONS :
 * 												1- TIMER_COUNTER_0_NORMAL_MODE
 * 												2- TIMER_COUNTER_0_PWM_PHASE_CORRECT_MODE
 * 												3- TIMER_COUNTER_0_COMAPRE_MATCH_MODE
 * 												4- TIMER_COUNTER_0_PWM_FAST
 */
#define TIMER_COUNTER_0_MODE_OF_OPERATION	TIMER_COUNTER_0_PWM_PHASE_CORRECT_MODE


#if TIMER_COUNTER_0_MODE_OF_OPERATION == TIMER_COUNTER_0_COMAPRE_MATCH_MODE

/*	OUTPUT_COMPARE_PIN_OC0_MODE OPTIONS :
 * 												1- OC0_DISABLED
 * 												2- TOGGLE_OC0_ON_CM
 * 												3- CLEAR_OC0_ON_CM
 * 												4- SET_OC0_ON_CM
 */
#define OUTPUT_COMPARE_PIN_OC0_MODE 	OC0_DISABLED

#define TIMER_0_COMP_MATCH_VALUE		125


#elif TIMER_COUNTER_0_MODE_OF_OPERATION == TIMER_COUNTER_0_PWM_FAST

/*	OUTPUT_COMPARE_PIN_OC0_MODE OPTIONS :
 * 												1- OC0_DISABLED
 * 												3- CLR_OC0_ON_COMP_SET_OC0_ON_TOP	// Non-Inverted Mode //
 * 												4- SET_OC0_ON_COMP_CLR_OC0_ON_TOP	// Inverted Mode //
 */
#define OUTPUT_COMPARE_PIN_OC0_MODE		CLR_OC0_ON_COMP_SET_OC0_ON_TOP

#define TIMER_0_COMP_MATCH_VALUE	64

#endif

#if TIMER_COUNTER_0_MODE_OF_OPERATION == TIMER_COUNTER_0_PWM_PHASE_CORRECT_MODE

/*	OUTPUT_COMPARE_PIN_OC0_MODE OPTIONS :
 * 										1- OC0_DISABLED
 * 										3- CLR_OC0_ON_COMP_UPCOUNT_SET_OC0_ON_COMP_DOWNCOUNT // Non-Inverted Mode //
 * 										4- SET_OC0_ON_COMP_DOWNCOUNT_CLR_OC0_ON_COMP_UPCOUNT // Inverted Mode //
 */

#define OUTPUT_COMPARE_PIN_OC0_MODE		CLR_OC0_ON_COMP_UPCOUNT_SET_OC0_ON_COMP_DOWNCOUNT

#define TIMER_0_COMP_MATCH_VALUE	64

#endif

/*	TIMER_COUNTER_0_PRESCALER OPTIONS :
 * 										1- TIMER_COUNTER_0_DISABLE
* 										2- SYSTEM_CLOCK
* 										3- SC_DIV_BY_8
* 										4- SC_DIV_BY_64
* 										5- SC_DIV_BY_256
* 										6- SC_DIV_BY_1024
* 										7- EXTR_CLK_T0_FALLING_EDGE
* 										8- EXTR_CLK_T0_RISING_EDGE
 */
#define TIMER_COUNTER_0_PRESCALER	SC_DIV_BY_8



#endif
