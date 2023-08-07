/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: EXTI						***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"

/* Global array of pointer to functions to Hold INT0,INT1,INT2 ISR Address */
void (*AvoidCallBack[3])(void) = {NULL , NULL , NULL};

void EXTI_voidInt0Innit(void){
#if INT0_SENSE == EXTI_LOW_LEVEL
	CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC00);
	CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC01);
#elif INT0_SENSE == EXTI_IOC
	SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC00);
	CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC01);
#elif INT0_SENSE == EXTI_FALLING_EDGE
	CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC00);
	SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC01);
#elif INT0_SENSE == EXTI_RISING_EDGE
	SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC00);
	SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC01);
#else
#error "WRONG INT0_SENSE CONFIG OPTION"
#endif
	/*check peripheral interrupt enable state */
#if INT0_INITIAL_STATE == EXTI_ENABLE
	SET_BIT(EXTI_u8GICR, EXTI_u8GICR_INT0);
#elif INT0_INITIAL_STATE == EXTI_DISABLE
	CLR_BIT(EXTI_u8GICR, EXTI_u8GICR_INT0);
#else
#error "WRONG INT0_INITIAL_STATE CONFIG OPTION"
#endif
}

void EXTI_voidInt1Innit(void){
#if INT1_SENSE == EXTI_LOW_LEVEL
	CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC10);
	CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC11);
#elif INT1_SENSE == EXTI_IOC
	SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC10);
	CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC11);
#elif INT1_SENSE == EXTI_FALLING_EDGE
	CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC10);
	SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC11);
#elif INT1_SENSE == EXTI_RISING_EDGE
	SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC10);
	SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC11);
#else
#error "WRONG INT1_SENSE CONFIG OPTION"
#endif

	/*check peripheral interrupt enable state */
#if INT1_INITIAL_STATE == EXTI_ENABLE
	SET_BIT(EXTI_u8GICR, EXTI_u8GICR_INT1);
#elif INT1_INITIAL_STATE == EXTI_DISABLE
	CLR_BIT(EXTI_u8GICR, EXTI_u8GICR_INT1);
#else
#error "WRONG INT1_INITIAL_STATE CONFIG OPTION"
#endif
}

void EXTI_voidInt2Innit(void){
#if INT2_SENSE == EXTI_FALLING_EDGE
	CLR_BIT(EXTI_u8MCUCSR , EXTI_u8MCUCSR_INT2);
#elif INT2_SENSE == EXTI_RISING_EDGE
	SET_BIT(EXTI_u8MCUCSR , EXTI_u8MCUCSR_INT2);
#else
#error "WRONG INT2_SENSE CONFIG OPTION"
#endif
	/*check peripheral interrupt enable state */
#if INT2_INITIAL_STATE == EXTI_ENABLE
	SET_BIT(EXTI_u8GICR, EXTI_u8GICR_INT2);
#elif INT2_INITIAL_STATE == EXTI_DISABLE
	CLR_BIT(EXTI_u8GICR, EXTI_u8GICR_INT2);
#else
#error "WRONG INT2_INITIAL_STATE CONFIG OPTION"
#endif
}


u8 EXTI_u8SetSenseControl_INT0(u8 Copy_u8ISC){
	u8 Loc_u8Error = NO_ERROR;
	/* SET SENSE CONTROL FOR INT0 bit1,bit0 MCUCR */
	switch(Copy_u8ISC){
	case EXTI_LOW_LEVEL : /* 00 */
		CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC00);
		CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC01);
		break;
	case EXTI_IOC :	/* 01 */
		SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC00);
		CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC01);
		break;
	case EXTI_FALLING_EDGE : /* 10 */
		CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC00);
		SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC01);
		break;
	case EXTI_RISING_EDGE :	/* 11 */
		SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC00);
		SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC01);
		break;
	default :
		Loc_u8Error = ERROR;
	}
	return Loc_u8Error;
}

u8 EXTI_u8SetSenseControl_INT1(u8 Copy_u8ISC){
	u8 Loc_u8Error = NO_ERROR;
	/* SET SENSE CONTROL FOR INT1 bit3,bit2 MCUCR */
	switch(Copy_u8ISC){
	case EXTI_LOW_LEVEL : /* 00*/
		CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC10);
		CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC11);
		break;
	case EXTI_IOC :	/* 01 */
		SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC10);
		CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC11);
		break;
	case EXTI_FALLING_EDGE :	/* 10 */
		CLR_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC10);
		SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC11);
		break;
	case EXTI_RISING_EDGE :	/* 11 */
		SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC10);
		SET_BIT(EXTI_u8MCUCR , EXTI_u8MCUCR_ISC11);
		break;
	default :
		Loc_u8Error = ERROR;
	}
	return Loc_u8Error;
}

u8 EXTI_u8SetSenseControl_INT2(u8 Copy_u8ISC){
	u8 Loc_u8Error = NO_ERROR;
	/* SET SENSE CONTROL FOR INT2 bit6 MCUCSR*/
	switch(Copy_u8ISC){
	case EXTI_FALLING_EDGE :	/* 0 */
		CLR_BIT(EXTI_u8MCUCSR , EXTI_u8MCUCSR_INT2);
		break;
	case EXTI_RISING_EDGE :	/* 1 */
		SET_BIT(EXTI_u8MCUCSR , EXTI_u8MCUCSR_INT2);
		break;
	default :
		Loc_u8Error = ERROR;
	}
	return Loc_u8Error;
}


u8 EXTI_u8EXTI_EnDis(u8 Copy_u8INT_Index, u8 Copy_u8EnDis){
	u8 Loc_u8Error = NO_ERROR;
	/*Check On Copy_u8EnDis argument */
	if( (Copy_u8EnDis != EXTI_ENABLE) && (Copy_u8EnDis != EXTI_DISABLE) ){
		Loc_u8Error = ERROR;
	}
	else {
		/* Peripheral Interrupt Enable */
		switch(Copy_u8INT_Index)
		{
		case EXTI_u8INT0 :
			ASS_BIT(EXTI_u8GICR, EXTI_u8GICR_INT0, Copy_u8EnDis);
			break;
		case EXTI_u8INT1 :
			ASS_BIT(EXTI_u8GICR, EXTI_u8GICR_INT1, Copy_u8EnDis);
			break;
		case EXTI_u8INT2 :
			ASS_BIT(EXTI_u8GICR, EXTI_u8GICR_INT2, Copy_u8EnDis);
			break;
		default :
			Loc_u8Error = ERROR;
		}
	}
	return Loc_u8Error;
}


/*
 * // Global pointer to function to hold int0 ISR Address *
 *void (*EXTI_PvInt0Func)(void) = NULL;
 */
u8 EXTI_u8SetCallBack(u8 Copy_u8EXTI_Index, void (*Copy_PvEXTIFunc)(void) ){
	u8 Loc_u8Error = NO_ERROR;
	if( Copy_PvEXTIFunc != NULL ){
		AvoidCallBack[Copy_u8EXTI_Index] = Copy_PvEXTIFunc;
	}
	else {
		Loc_u8Error = ERROR;
	}
	return Loc_u8Error;
}


/* ISR of INT0 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(AvoidCallBack[0] != NULL){
		AvoidCallBack[0]();
	}
	else
		return;
}
/* ISR of INT1 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(AvoidCallBack[1] != NULL){
		AvoidCallBack[1]();
	}
	else
		return;
}
/* ISR of INT2 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if(AvoidCallBack[2] != NULL){
		AvoidCallBack[2]();
	}
	else
		return;
}
