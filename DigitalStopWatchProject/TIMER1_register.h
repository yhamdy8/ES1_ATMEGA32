/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: TIMER1						***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/



#ifndef  TIMER1_REGISTER_H_
#define  TIMER1_REGISTER_H_

//////////////////////////////////////////////////////////////////////////////////////////////////////////
#define TIMER_u8TIMSK		*((volatile u8*)0x59)	// 8bit TIMER0/COUNTER0 Interrupt Mask Register
#define TIMSK_OCIE0		1	// OP Compare Match INTERRUPT ENABLE
#define TIMSK_TOIE0		0	// OV-FLOW INTERRUPT ENABLE

#define TIMSK_TICIE1	5	// INPUT Capture Interr enable
#define TIMSK_OCIE1A	4	// Output Compare A Match Interr Enable

#define TIMSK_OCIE1B	3	// Output Compare B Match Interr Enable
#define TIMSK_TOIE1		2	// Timer1 OV-Flow INTERRUPT ENABLE

///////////////////////////////////////////////////////////////////////////////////////////////////
		/* TIMER_COUNTER_1  REGISTERS */
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


#endif
