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

///////////////////////////////////////////////////////////////////////////////////////////////////
/*		/* TIMER_COUNTER_1  REGISTERS
#define TIMER1_TCCR1A		*((volatile u8*)0x4F)	// 8bit TIMER1/COUNTER1 Control Register
#define TCCR1A_COM1A1	7		// OC1A options
#define TCCR1A_COM1A0	6

#define TCCR1A_COM1B1	5		//OC1B options
#define TTCR1A_COM1B0	4

#define TCCR1A_FOC1A	3		//force comp match on OC1A
#define TTCR1A_FOC1B	2		//force Comp Match on OC1B

#define TTCR1A_WGM11	1		// Wave Form Generation Mode b2
#define TTCR1A_WGM10	0		// Wave form generation Mode b1


#define TIMER1_TCCR1B		*((volatile u8*)0x4E)	// 8bit TIMER1/COUNTER1 Control Register
#define TCCR1B_WGM13	4		// Wave form generation Mode b4
#define TCCR1B_WGM12	3		// Wave form generation Mode b3

#define TCCR1B_CS12		2		// Prescaler Select
#define TCCR1B_CS11		1
#define TCCR1B_CS10		0

#define TIMER1_ICR1H		*((volatile u8*)0x47)
#define TIMER1_ICR1L		*((volatile u8*)0x46)
#define TIMER1_ICR1			*((volatile u16*)0x46)


#define TIMER1_OCR1AH		*((volatile u8*)0x4B)
#define TIMER1_OCR1AL		*((volatile u8*)0x4A)
#define TIMER1_OCR1A		*((volatile u16*)0x4A)	// Compare Match Reg A


#define TIMER1_OCR1BH		*((volatile u8*)0x49)
#define TIMER1_OCR1BL		*((volatile u8*)0x48)
#define TIMER1_OCR1B		*((volatile u16*)0x48)	// Compare Match Reg B

#define TIMER1_TCNT1H		*((volatile u8*)0x4D)
#define TIMER1_TCNT1L		*((volatile u8*)0x4C)
#define TIMER1_TCNT1		*((volatile u16*)0x4C)
*/

#endif
