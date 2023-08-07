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


#ifndef  TIMER_1_PRIVATE_H_
#define  TIMER_1_PRIVATE_H_

#define TIMER_COUNTER_1_NORMAL_MODE				1
#define TIMER_COUNTER_1_PWM_PHASE_CORRECT_MODE	2
#define TIMER_COUNTER_1_COMAPRE_MATCH_MODE		3
#define TIMER_COUNTER_1_PWM_FAST				4

#define OC1_DISABLED    	1
#define TOGGLE_OC1_ON_CM	2
#define CLEAR_OC1_ON_CM 	3
#define SET_OC1_ON_CM   	4

#define OC1_DISABLED                  	1
#define CLR_OC1_ON_COMP_SET_OC1_ON_TOP	3
#define SET_OC1_ON_COMP_CLR_OC1_ON_TOP	4

#define  TIMER_COUNTER_1_DISABLE  	0
#define  SYSTEM_CLOCK             	1
#define  SC_DIV_BY_8              	2
#define  SC_DIV_BY_64             	3
#define  SC_DIV_BY_256            	4
#define  SC_DIV_BY_1024           	5
#define  EXTR_CLK_T0_FALLING_EDGE 	6
#define  EXTR_CLK_T0_RISING_EDGE  	7

//#define TIMER0_PRESCALER_MASK	0b11111000
//#define NULL	((void*) 0)

////////////////////////////////////////////////////////////
#define TIMER1_PRESCALER_MASK 0b11111000

#endif
