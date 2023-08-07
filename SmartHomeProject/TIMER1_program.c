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

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_interface.h"
#include "TIMER1_register.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"


static void(*ICU_pvCallBackFunc)(void)=NULL;

void TIMER_COUNTER_1_voidInit(void){
	//Setting Fast PWM Non-inverting Mode --> Clr OC1A/OC1B on compare match, set OC1A/OC1B at TOP
	CLR_BIT(TIMER1_TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TIMER1_TCCR1A, TCCR1A_COM1A1);
	// Setting Mode 14 Fast PWM
	CLR_BIT(TIMER1_TCCR1A, TTCR1A_WGM10);
	SET_BIT(TIMER1_TCCR1A, TTCR1A_WGM11);
	SET_BIT(TIMER1_TCCR1B, TCCR1B_WGM12);
	SET_BIT(TIMER1_TCCR1B, TCCR1B_WGM13);
	// Set Prescaler Value
	TIMER1_TCCR1B &= TIMER1_PRESCALER_MASK;
	TIMER1_TCCR1B |= TIMER_COUNTER_1_PRESCALER;

	/* init @normal mode , prescaler : div by 8
	// by default its in normal mode
	// set prescaler
	TIMER1_TCCR1B &= TIMER1_PRESCALER_MASK;
	TIMER1_TCCR1B = TIMER_COUNTER_1_PRESCALER;
	*/
}
void TIMER1_voidStopTimer1(void){
	TIMER1_TCCR1B=0;
}
void ICU_voidInit(void){
	// Set trigger source to rising edge initially
	SET_BIT(TIMER1_TCCR1B, TCCR1B_ICES1);
	// Enable Ip Capture Interrupt
	SET_BIT(TIMER_u8TIMSK, TIMSK_TICIE1);
}

u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge){
	u8 ErrorStatus = NO_ERROR;
	if( Copy_u8Edge == ICU_RISING_EDGE)
		SET_BIT(TIMER1_TCCR1B, TCCR1B_ICES1);
	else if( Copy_u8Edge == ICU_FALLING_EDGE)
		CLR_BIT(TIMER1_TCCR1B, TCCR1B_ICES1);
	else ErrorStatus = ERROR;
	return ErrorStatus;
}

u8 ICU_u8EnDisInterrupt(u8 Copy_u8EnDis){
	u8 ErrorStatus = NO_ERROR;
	if( (Copy_u8EnDis != ICU_EN_INTERRUPT) || (Copy_u8EnDis != ICU_DIS_INTERRUPT) ){
		ErrorStatus = ERROR;
	}else{
	ASS_BIT(TIMER_u8TIMSK, TIMSK_TICIE1, Copy_u8EnDis);
	}
	return ErrorStatus;
}

u16 ICU_u16ReadInputCapture(void){
	return TIMER1_ICR1;
}


void TIMER1_voidSetTimerValue(u16 Copy_u16Value){
	TIMER1_TCNT1 = Copy_u16Value;
}

u16 TIMER1_u16ReadTimer1Value(void){
	return TIMER1_TCNT1;
}

void TIMER1_voidSetChannelACompareMatchValue(u16 Copy_u16Value){
	// used to assign ON time for servo motor
	TIMER1_OCR1A = Copy_u16Value;
}

void TIMER1_voidICR(u16 Copy_u16ICRValue){
	// used to set Top Value @ fast pwm mode 14
	TIMER1_ICR1 = Copy_u16ICRValue;
}


u8 ICU_u8SetCallBack( void (*Copy_pvCallBackFunc)(void) ){
	u8 ErrorStatus =NO_ERROR;
	if(Copy_pvCallBackFunc == NULL)
		ErrorStatus = NULL_POINTER;
	else
		ICU_pvCallBackFunc = Copy_pvCallBackFunc;
	return ErrorStatus;
}


// TIMER1 Capture Event (ICU) ISR
void __vector_6(void) __attribute__((signal));
void __vector_6(void){
	if(ICU_pvCallBackFunc != NULL){
		ICU_pvCallBackFunc();
	}
}
