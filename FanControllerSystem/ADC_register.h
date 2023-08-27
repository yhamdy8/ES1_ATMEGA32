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

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADC_u8ADMUX		*((volatile u8*) 0x27)	// MUILTIPLEXER SELECTION REGISTER
#define ADMUX_REFS1	7							// REFERENCE SELECTION BIT1
#define ADMUX_REFS0	6							// REFERENCE SELECTION BIT0
#define ADMUX_ADLAR	5							// ADC LEFT-ADJUST RESULT


#define ADC_u8ADCSRA	*((volatile u8*) 0x26)	// ADC CONTROL & STATUS REGISTER
#define ADCSRA_ADEN	7							// ADC ENABLE
#define ADCSRA_ADSC	6                 		  	// ADC START CONVERSION
#define ADCSRA_ADATE	5                   	// ADC AUTO TRIGGER ENABLE
#define ADCSRA_ADIF	4                   		// ADC INTERRUPT FLAG
#define ADCSRA_ADIE	3                   		// ADC INTERRUPT ENABLE
#define ADCSRA_ADPS2	2                   	// ADC PRESCALER SELECT BIT2 /* CLOCK SELECTION */
#define ADCSRA_ADPS1	1                   	// ADC PRESCALER SELECT BIT1
#define ADCSRA_ADPS0	0                   	// ADC PRESCALER SELECT BIT0


#define ADC_u8SFIOR		*((volatile u8*) 0x26) // ADC AUTO TRIGGER FLAG


#define ADC_u8ADCH		*((volatile u8*) 0x25)	// ADC HIGH REGISTER
#define ADC_u8ADCL		*((volatile u8*) 0x24)	// ADC LOW REGISTER

#define ADC				*((volatile u16*) 0x24)	// ADCH & ADCL


#endif
