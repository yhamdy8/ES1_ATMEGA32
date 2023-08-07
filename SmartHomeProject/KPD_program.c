/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	HAL							***********************/
/************************		DRIVER: KPD							***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/


#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"


u8 KPD_u8GetPressedKey(void){
	u8 Loc_u8PressedKey= KPD_NO_PRESSED_KEY	,Loc_u8COLIdx, Loc_u8ROWIdx, Loc_u8PinState;
		/* static to be saved @ .data instead of stack memory cuz arrays consume lots of memory */
	static u8 Loc_u8KPDArr[KPD_ROW_NUM][KPD_COL_NUM]= KPD_ARR_VAL;
	static u8 Loc_u8KPDCOLArr[KPD_COL_NUM]={KPD_COL_PIN_0, KPD_COL_PIN_1, KPD_COL_PIN_2, KPD_COL_PIN_3};
	static u8 Loc_u8KPDROWArr[KPD_ROW_NUM]={KPD_ROW_PIN_0, KPD_ROW_PIN_1, KPD_ROW_PIN_2, KPD_ROW_PIN_3};

	for(Loc_u8COLIdx=0; Loc_u8COLIdx < KPD_COL_NUM; Loc_u8COLIdx++){
			/* ACTIVATE CURRENT COLUMN */
		DIO_u8_Set_Pin_Value(KPD_COL_PORT, Loc_u8KPDCOLArr[Loc_u8COLIdx], DIO_u8_PIN_LOW);
			/* SEARCH IF A ROW IS LOW THUS A KEY IS PRESSED */
		for(Loc_u8ROWIdx=0; Loc_u8ROWIdx < KPD_ROW_NUM; Loc_u8ROWIdx++ ){
			DIO_u8_Get_Pin_Value(KPD_ROW_PORT, Loc_u8KPDROWArr[Loc_u8ROWIdx], &Loc_u8PinState);
				/* CHECK IF SWITCH IS PRESSED */
			if( DIO_u8_PIN_LOW == Loc_u8PinState){
				Loc_u8PressedKey = Loc_u8KPDArr[Loc_u8ROWIdx][Loc_u8COLIdx];
					/* Polling ( wait till button is released ) */
				while( DIO_u8_PIN_LOW == Loc_u8PinState	){
					DIO_u8_Get_Pin_Value(KPD_ROW_PORT, Loc_u8KPDROWArr[Loc_u8ROWIdx], &Loc_u8PinState);
				}
				return Loc_u8PressedKey;
			}
		}
			/* DEACTIVATE CURRENT COLUMN */
		DIO_u8_Set_Pin_Value(KPD_COL_PORT, Loc_u8KPDCOLArr[Loc_u8COLIdx], DIO_u8_PIN_HIGH);
	}

	return Loc_u8PressedKey;
}
