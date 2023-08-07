/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: ADC							***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define DIV_2  	1
#define DIV_4  	2
#define DIV_8  	3
#define DIV_16 	4
#define DIV_32 	5
#define DIV_64 	6
#define	DIV_128	7

#define REFVOL_5V		1
#define REFVOL_2DOT56V 	2
#define EXTERNAL_VOLT	3

#define AUTO_TRIGGER_ENABLE		1
#define AUTO_TRIGGER_DISABLE	2

#define ADC_EVENT_ON_INTERRUPT	1
#define ADC_EVENT_ON_POLLING	2

	/* ADC AUTO TRIGGER SOURCE */
#define ADTS_FREE_RUNNING_MODE					0
#define ADTS_ANALOG_COMPARATOR					1
#define ADTS_EXTI0								2
#define ADTS_TIMER_COUNTER0_COMPARE_MATCH		3
#define ADTS_TIMER_COUNTER0_OVERFLOW			4
#define ADTS_TIMER_COUNTER_COMPARE_MATCH_B		5
#define ADTS_TIMER_COUNTER1_OVERFLOW			6
#define ADTS_TIMER_COUNTER1_CAPTURE_EVENT		7


#define ADC_PRESCALER_MASK	0b11111000
#define ADC_MUX_MASK		0b11100000
#define ADC_AUTO_TRIG_MASK 	0b00011111
#define NULL ((void*)0)

#define ADC_IDLE	0
#define ADC_BUSY	1
#endif
