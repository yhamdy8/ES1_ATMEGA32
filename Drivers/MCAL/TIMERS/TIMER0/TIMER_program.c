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

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"


/*
 * ptr 0 -> TIMER 0 ISR COMP MATH
 * ptr 1 -> TIMER 0 ISR OV-FLOW
 * ptr 2 -> TIMER 2 ISR COMP MATH
 * ptr 3 -> TIMER 2 ISR OV-FLOW
 */

static void (*TIMER_COUNTER_0_pvCallBackFunc[4])(void) = {NULL,NULL,NULL,NULL};


void TIMER_COUNTER_0_voidInit(void){
#if TIMER_COUNTER_0_MODE_OF_OPERATION == TIMER_COUNTER_0_NORMAL_MODE
	/* OVER-FLOW MODE bit6, bit3 00 */
	CLR_BIT(TIMER_u8TCCR0, TCCR0_WGM00);
	CLR_BIT(TIMER_u8TCCR0, TCCR0_WGM01);

#elif TIMER_COUNTER_0_MODE_OF_OPERATION == TIMER_COUNTER_0_PWM_PHASE_CORRECT_MODE
	/* PWM, PHASE CORRECT bit6, bit3 01*/
	SET_BIT(TIMER_u8TCCR0, TCCR0_WGM00);
	CLR_BIT(TIMER_u8TCCR0, TCCR0_WGM01);
#if	OUTPUT_COMPARE_PIN_OC0_MODE == OC0_DISABLED
	/* bit5,bit4 00 */
	CLR_BIT(TIMER_u8TCCR0, TTCR0_COM00);
	CLR_BIT(TIMER_u8TCCR0, TTCR0_COM01);
#elif OUTPUT_COMPARE_PIN_OC0_MODE == CLR_OC0_ON_COMP_UPCOUNT_SET_OC0_ON_COMP_DOWNCOUNT
		/* bit5,bit4 10 */
	CLR_BIT(TIMER_u8TCCR0, TTCR0_COM00);
	SET_BIT(TIMER_u8TCCR0, TTCR0_COM01);
#elif OUTPUT_COMPARE_PIN_OC0_MODE == SET_OC0_ON_COMP_DOWNCOUNT_CLR_OC0_ON_COMP_UPCOUNT
		/* bit5,bit4 11 */
	SET_BIT(TIMER_u8TCCR0, TTCR0_COM00);
	SET_BIT(TIMER_u8TCCR0, TTCR0_COM01);
#elif
#error "Wrong OUTPUT_COMPARE_PIN_OC0_MODE Config Option "

#endif

#elif TIMER_COUNTER_0_MODE_OF_OPERATION == TIMER_COUNTER_0_COMAPRE_MATCH_MODE
	/* CTC MODE bit6,bit3 10 */
	CLR_BIT(TIMER_u8TCCR0, TCCR0_WGM00);
	SET_BIT(TIMER_u8TCCR0, TCCR0_WGM01);
	/* OC0 pin Setup */
#if	OUTPUT_COMPARE_PIN_OC0_MODE == OC0_DISABLED
	/* bit5,bit4 00 */
	CLR_BIT(TIMER_u8TCCR0, TTCR0_COM00);
	CLR_BIT(TIMER_u8TCCR0, TTCR0_COM01);
#elif OUTPUT_COMPARE_PIN_OC0_MODE == TOGGLE_OC0_ON_CM
	/* bit5,bit4 01 */
	SET_BIT(TIMER_u8TCCR0, TTCR0_COM00);
	CLR_BIT(TIMER_u8TCCR0, TTCR0_COM01);
#elif OUTPUT_COMPARE_PIN_OC0_MODE == CLEAR_OC0_ON_CM
	/* bit5,bit4 10 */
	CLR_BIT(TIMER_u8TCCR0, TTCR0_COM00);
	SET_BIT(TIMER_u8TCCR0, TTCR0_COM01);
#elif OUTPUT_COMPARE_PIN_OC0_MODE == SET_OC0_ON_CM
	/* bit5,bit4 11 */
	SET_BIT(TIMER_u8TCCR0, TTCR0_COM00);
	SET_BIT(TIMER_u8TCCR0, TTCR0_COM01);
#elif
#error "Wrong OUTPUT_COMPARE_PIN_OC0_MODE Config Option"
#endif

#elif TIMER_COUNTER_0_MODE_OF_OPERATION == TIMER_COUNTER_0_PWM_FAST
	SET_BIT(TIMER_u8TCCR0, TCCR0_WGM00);
	SET_BIT(TIMER_u8TCCR0, TCCR0_WGM01);

#if	OUTPUT_COMPARE_PIN_OC0_MODE == OC0_DISABLED
	/* bit5,bit4 00 */
	CLR_BIT(TIMER_u8TCCR0, TTCR0_COM00);
	CLR_BIT(TIMER_u8TCCR0, TTCR0_COM01);
#elif OUTPUT_COMPARE_PIN_OC0_MODE == CLR_OC0_ON_COMP_SET_OC0_ON_TOP
		/* bit5,bit4 10 */
	CLR_BIT(TIMER_u8TCCR0, TTCR0_COM00);
	SET_BIT(TIMER_u8TCCR0, TTCR0_COM01);
#elif OUTPUT_COMPARE_PIN_OC0_MODE == SET_OC0_ON_COMP_CLR_OC0_ON_TOP
		/* bit5,bit4 11 */
	SET_BIT(TIMER_u8TCCR0, TTCR0_COM00);
	SET_BIT(TIMER_u8TCCR0, TTCR0_COM01);
#elif
#error "Wrong OUTPUT_COMPARE_PIN_OC0_MODE Config Option "

#endif

#elif
#error "Wrong TIMER_COUNTER_0_MODE_OF_OPERATION Config. Option"
#endif

	/* TIMER Peripheral Interrupt enable */
#if TIMER_COUNTER_0_MODE_OF_OPERATION == TIMER_COUNTER_0_NORMAL_MODE
	/*	INTERRUPT ON OV-FLOW */
	SET_BIT(TIMER_u8TIMSK, TIMSK_TOIE0);
#elif TIMER_COUNTER_0_MODE_OF_OPERATION == TIMER_COUNTER_0_COMAPRE_MATCH_MODE
	/*	INTERRUPT ON COMPARE MATCH */
	SET_BIT(TIMER_u8TIMSK, TIMSK_OCIE0);
#endif

#if TIMER_COUNTER_0_MODE_OF_OPERATION == TIMER_COUNTER_0_COMAPRE_MATCH_MODE || TIMER_COUNTER_0_PWM_PHASE_CORRECT_MODE || TIMER_COUNTER_0_MODE_OF_OPERATION == TIMER_COUNTER_0_PWM_FAST
	/* Set COMPARE MATCH VALUE */
	TIMER_u8OCR0 = TIMER_0_COMP_MATCH_VALUE;
#endif
	/* TIMER Peripheral ENable & choose prescaler */
	TIMER_u8TCCR0 &= TIMER0_PRESCALER_MASK;
	TIMER_u8TCCR0 |= TIMER_COUNTER_0_PRESCALER;
}


void TIMER0_voidSetCompareMatchValue(u8 Copy_u8Value){
	TIMER_u8OCR0 = Copy_u8Value;
}

void TIMER0_voidSetPreloadValue(u8 Copy_u8Value){
	TIMER_u8TCNT0 = Copy_u8Value;
}

u8 TIMER0_u8SetCallBack_COMPMATCH( void (*Copy_pvCallBackFunc)(void) ){
	u8 Loc_u8ErrorState = NO_ERROR;
	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER_COUNTER_0_pvCallBackFunc[0] = Copy_pvCallBackFunc;
	}else Loc_u8ErrorState = NULL_POINTER;
	return Loc_u8ErrorState;
}

u8 TIMER0_u8SetCallBack_OVFLOW( void (*Copy_pvCallBackFunc)(void) ){
	u8 Loc_u8ErrorState = NO_ERROR;
	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER_COUNTER_0_pvCallBackFunc[1] = Copy_pvCallBackFunc;
	}else Loc_u8ErrorState = NULL_POINTER;
	return Loc_u8ErrorState;
}


/* ISR OF TIMER0/COUNTER0 COMPARE MATH */
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	if(TIMER_COUNTER_0_pvCallBackFunc[0] != NULL)
	{
		TIMER_COUNTER_0_pvCallBackFunc[0]();
	}
}


/* ISR OF TIMER0/COUNTER0 OV-FLOW */
void __vector_11(void) __attribute__((signal));
void __vector_11(void){
	if(TIMER_COUNTER_0_pvCallBackFunc[1] != NULL)
	{
		TIMER_COUNTER_0_pvCallBackFunc[1]();
	}
}

