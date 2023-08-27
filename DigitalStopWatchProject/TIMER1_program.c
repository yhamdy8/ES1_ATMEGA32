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

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_config.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_register.h"

void (*CallBackFunc)(void)= NULL;


void TIMER_COUNTER_1_voidInit(void){
	/* Setting Fast PWM Non-inverting Mode --> Clr OC1A/OC1B on compare match, set OC1A/OC1B at TOP */
	CLR_BIT(TIMER1_TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TIMER1_TCCR1A, TCCR1A_COM1A1);
	/* Setting Mode 14 Fast PWM */
	CLR_BIT(TIMER1_TCCR1A, TTCR1A_WGM10);
	SET_BIT(TIMER1_TCCR1A, TTCR1A_WGM11);
	SET_BIT(TIMER1_TCCR1B, TCCR1B_WGM12);
	SET_BIT(TIMER1_TCCR1B, TCCR1B_WGM13);
	/* Set Prescaler Value */
	TIMER1_TCCR1B &= TIMER1_PRESCALER_MASK;
	TIMER1_TCCR1B |= TIMER_COUNTER_1_PRESCALER;
}

void TIMER1_voidSetChannelACompareMatchValue(u32 Copy_u8Value){
	TIMER1_OCR1A = Copy_u8Value;
}

void TIMER1_voidICR(u16 Copy_u16ICRValue){
	TIMER1_ICR1 = Copy_u16ICRValue;
}

void TIMER1_voidSTOPWATCHFUNC( void (*Copy_pvCallBackFunc)(void) ){
	/* CTC MODE */
	CLR_BIT(TIMER1_TCCR1A, TTCR1A_WGM10);
	CLR_BIT(TIMER1_TCCR1A, TTCR1A_WGM11);
	SET_BIT(TIMER1_TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TIMER1_TCCR1B, TCCR1B_WGM13);
	/* Set Prescaler Value */
	TIMER1_TCCR1B &= TIMER1_PRESCALER_MASK;
	TIMER1_TCCR1B |= TIMER_COUNTER_1_PRESCALER;

	TIMER1_voidSetChannelACompareMatchValue(50000); // chosen 50k tick counts,, cuz when 1 divided by it, gives a int (whole) number
		//required time / tick time ==  1 / (50 000 * 10^-6) == 20 --> _1SECOND

	CallBackFunc = Copy_pvCallBackFunc;
	/* Enable COMP MATCH A interrupt*/
	SET_BIT(TIMER_u8TIMSK, TIMSK_OCIE1A);

}

void Timer1_voidPauseStop(void){
	TIMER1_TCCR1B &= TIMER1_PRESCALER_MASK;
}

void TIMER1_voidRESUME(void){
	TIMER1_TCCR1B &= TIMER1_PRESCALER_MASK;
	TIMER1_TCCR1B |= TIMER_COUNTER_1_PRESCALER;
}

/* ISR of Timer1 compare match A */
void __vector_7(void) __attribute__((signal));
void __vector_7(void){
	if(CallBackFunc != NULL)
	{
		CallBackFunc();
	}
}
