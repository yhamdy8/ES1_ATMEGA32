/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: WDT							***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WDT_interface.h"
#include "WDT_config.h"
#include "WDT_private.h"
#include "WDT_register.h"

void WDT_voidSleep(u8 Copy_u8Value){
	//Clear Prescaler Bits
	WDT_u8WTDCR &= WDT_PRESCALER_MASK;
	//Set the required prescaler
	WDT_u8WTDCR |= Copy_u8Value;
}

void WDT_voidEnable(void){
	SET_BIT(WDT_u8WTDCR, WDTCR_WDE);
}

void WDT_voidDisable(void){
	//step 1,, write logic 1 to B3 & logic 1 to B4 @ same cycle
	WDT_u8WTDCR |= 0b00011000;
	//step 2,, within next 4 clk cycles write logical 0 to B3
	WDT_u8WTDCR = 0;

}
