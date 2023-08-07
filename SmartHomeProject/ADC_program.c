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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_register.h"

static void (*ADC_pvCallBackNotificationFile)(void)= NULL;

static u16* ADC_pu16Reading = NULL;

u8 ADC_u8BusyState = ADC_IDLE;

void ADC_voidInnit(void){
	/* SELECT Reference voltage */
#if ADC_REF_VOLT == REFVOL_5V
	/* AVCC as reference voltage 10 @ bit 7 bit 6 */
	SET_BIT(ADC_u8ADMUX, ADMUX_REFS0);
	CLR_BIT(ADC_u8ADMUX, ADMUX_REFS1);
#elif ADC_REF_VOLT == REFVOL_2DOT56V
	/* Internal 2.56V as reference voltage 11 @ bit 7 bit 6 */
	SET_BIT(ADC_u8ADMUX, ADMUX_REFS0);
	SET_BIT(ADC_u8ADMUX, ADMUX_REFS1);
#elif ADC_REF_VOLT == EXTERNAL_VOLT
	/* External volt on AREF as reference voltage 00 @ bit 7 bit 6 */
	CLR_BIT(ADC_u8ADMUX, ADMUX_REFS0);
	CLR_BIT(ADC_u8ADMUX, ADMUX_REFS1);
#elif
#error "Wrong ADC_REF_VOLT CONFIG OPTION"
#endif

	/* SELECT LEFT OR RIGHT ADJUSTMENT */
#if ADC_RESOLUTION == RESOLUTION_8BITS
	/* left adjusted as we are working 8 bits */
	SET_BIT(ADC_u8ADMUX, ADMUX_ADLAR);
#elif ADC_RESOLUTION == RESOLUTION_10BITS
	CLR_BIT(ADC_u8ADMUX, ADMUX_ADLAR);
#elif
#error "Wrong ADC_RESOLUTION CONFIG OPTION"
#endif

	/* AUTO TRIGGER MODE OR SINGLE CONVERSION MODE */
#if ADC_AUTO_TRIGGER == AUTO_TRIGGER_ENABLE
	/* AUTO TRIGGER ENABLE (ADATE) */
	SET_BIT(ADC_u8ADCSRA, ADCSRA_ADATE);
	/* MASK on Channel before Start conversion */
	ADC_u8ADMUX &= ADC_MUX_MASK;
	ADC_u8ADMUX |= AUTO_TRIGGER_CHANNEL;
	/* Setting Auto Trigger Source */
	ADC_u8SFIOR &= ADC_AUTO_TRIG_MASK;
	ADC_u8SFIOR |= ADC_AUTO_TRIGGER_SOURCE;
#elif ADC_AUTO_TRIGGER == AUTO_TRIGGER_DISABLE
	CLR_BIT(ADC_u8ADCSRA, ADCSRA_ADATE);
#elif
#error "Wrong ADC_AUTO_TRIGGER CONFIG OPTION"
#endif



	/* ADC PRESCALER SELECTION (CLK SELECTION) USING BIT MASKING */
	ADC_u8ADCSRA &= ADC_PRESCALER_MASK;	// Clear first 3bits b0 -> b2
	ADC_u8ADCSRA |= ADC_PRESCALER_SELECTION;	// Set New Value (Divide by 128)

	/* ADC Peripheral Enable */
	SET_BIT(ADC_u8ADCSRA, ADCSRA_ADEN);
}

u8 ADC_u8StartConversion_Synch(u8 Copy_u8Channel, u16* Copy_pu16Reading){
	u32 Loc_Counter=0;
	u8  Loc_ErrorState=0;
	if( ADC_u8BusyState == ADC_IDLE)
	{
		/* Turn ADC state to BUSY */
		ADC_u8BusyState = ADC_BUSY;
	/* BIT MASK First 5 bits b0 -> b4 */
	ADC_u8ADMUX &= ADC_MUX_MASK;
	/* Set the required channel into the MUX bits */
	ADC_u8ADMUX |= Copy_u8Channel;

	/* Start Conversion */
	SET_BIT(ADC_u8ADCSRA, ADCSRA_ADSC);

	/* POLLING -busy waiting- till the conversion complete flag is set or Counter Reaching Timeout value */
	while( ( ( GET_BIT(ADC_u8ADCSRA, ADCSRA_ADIF) ) == 0) && ( Loc_Counter != ADC_u32TIMEOUT) )
	{
		Loc_Counter++;
	}
	if( Loc_Counter == ADC_u32TIMEOUT )
	{
		/* Loop broken cuz timeout is reached */
		return TIMEOUT_ERROR;
	}else
	{
		/* Loop broken cuz flag is raised */
		/*Clear the ADC interrupt flag */
		SET_BIT(ADC_u8ADCSRA, ADCSRA_ADIF);

		/* return value */
#if ADC_RESOLUTION == RESOLUTION_8BITS
		*Copy_pu16Reading = ADC_u8ADCH;
		/* ADC FINISHED RETURN STATE TO IDLE */
		ADC_u8BusyState = ADC_IDLE;
#elif ADC_RESOLUTION == RESOLUTION_10BITS
		*Copy_pu16Reading = ADC;
		/* ADC FINISHED RETURN STATE TO IDLE */
		ADC_u8BusyState = ADC_IDLE;
#endif
	}
	}else{
		Loc_ErrorState = BUSY_FUNC;
	}
	return Loc_ErrorState = NO_ERRORS;
}

u8 ADC_u8StartConversion_ASynch(u8 Copy_u8Channel, u16* Copy_pu8Reading, void (*Copy_pvNotificationFunc)(void))
{
	u8 Loc_ErrorState=0;
	if( ADC_u8BusyState == ADC_IDLE )
	{
		if( ( Copy_pu8Reading == NULL ) || ( Copy_pvNotificationFunc == NULL) ){
			Loc_ErrorState = NULL_POINTER;
		}else
		{
			/* FLAG ADC as busy in order to make function off till ADC state is IDLE */
			ADC_u8BusyState = ADC_BUSY;

			/* Initialise the global Reading variable */
			ADC_pu16Reading = Copy_pu8Reading;

			/* Initialise the global callback notification function */
			ADC_pvCallBackNotificationFile = Copy_pvNotificationFunc;
			/* BIT MASK First 5 bits b0 -> b4 */
			ADC_u8ADMUX &= ADC_MUX_MASK;
			/* Set the required channel into the MUX bits */
			ADC_u8ADMUX |= Copy_u8Channel;
			/* Start Conversion */
			SET_BIT(ADC_u8ADCSRA, ADCSRA_ADSC);
			/* Enable ADC INTERRUPT */
			SET_BIT(ADC_u8ADCSRA, ADCSRA_ADIE);
		}
	}else
	{
		Loc_ErrorState = BUSY_FUNC;
	}
	return Loc_ErrorState;

}

void __vector_16(void) __attribute__((signal));
void __vector_16(void){

	/* Read ADC Result */
#if ADC_RESOLUTION == RESOLUTION_8BITS
	*ADC_pu16Reading = ADC_u8ADCH;
#elif ADC_RESOLUTION == RESOLUTION_10BITS
	*ADC_pu16Reading = ADC;
#endif
	/* SET ADC State -> IDLE */
	ADC_u8BusyState = ADC_IDLE;
	/* Invoke the CallBack Notification Function */
	ADC_pvCallBackNotificationFile();

	/* Disable ADC Conversion Complete Interrupt */
	CLR_BIT(ADC_u8ADCSRA, ADCSRA_ADIE);
}

