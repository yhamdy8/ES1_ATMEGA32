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



#ifndef  TIMER_REGISTER_H_
#define  TIMER_REGISTER_H_

		/* TIMER_COUNTER_0  REGISTERS */
#define TIMER_u8TCCR0		*((volatile u8*)0x53)	// 8bit TIMER0/COUNTER0 Control Register
#define TCCR0_WGM01		3	//	WaveForm Generation Mode bit1
#define TCCR0_WGM00		6	//	WaveForm Generation Mode bit0

#define TCCR0_FOC0		7 	// Force output compare,, Immediate compare match is forced

#define TTCR0_COM01		5	// Compare Match Output Mode bit1
#define TTCR0_COM00		4	// Compare Match Output Mode bit0

#define TCCR0_CS02		2   //Clock Select Bit (Prescaler) bit2
#define TCCR0_CS01		1   //Clock Select Bit (Prescaler) bit1
#define TCCR0_CS00		0   //Clock Select Bit (Prescaler) bit0


#define TIMER_u8TCNT0		*((volatile u8*)0x52)	// 8bit TIMER0/COUNTER0	Register	// SYSTEM COUNT FROM 0 --> 255 HERE // PUT PRESCALER VALUE HERE

#define TIMER_u8OCR0		*((volatile u8*)0x5C)	//OUTPUT COMPARE REGISTER 0 // PUT COMAPRE VALUE HERE

//////////////////////////////////////////////////////////////////////////////////////////////////////////
#define TIMER_u8TIMSK		*((volatile u8*)0x59)	// 8bit TIMER0/COUNTER0 Interrupt Mask Register
#define TIMSK_OCIE0		1	// OP Compare Match INTERRUPT ENABLE
#define TIMSK_TOIE0		0	// OV-FLOW INTERRUPT ENABLE

#define TIMSK_TICIE1	5	// INPUT Capture Interr enable
#define TIMSK_OCIE1A	4	// Output Compare A Match Interr Enable

#define TIMSK_OCIE1B	3	// Output Compare B Match Interr Enable
#define TIMSK_TOIE1		2	// Timer1 OV-Flow INTERRUPT ENABLE


#endif
