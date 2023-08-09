/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	HAL							***********************/
/************************		COMPONENT: LCD						***********************/
/************************		VERSION: 1.00						***********************/
/************************		DATE: 15/05/2023					***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_interface.h"

void LCD_void_Write_Command(u8 Copy_u8_Command){
	//Set RS 0 FOR CMD
DIO_u8_Set_Pin_Value( LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8_PIN_LOW);
/*	//Set RW LOW FOR WRITE
*	//DIO_u8_Set_Pin_Direction(LCD_CTRL_PORT, LCD_RW_PIN ,DIO_u8_PIN_OUTPUT);
*	DIO_u8_Set_Pin_Value(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8_PIN_LOW);
*
*		//Send command on Port
*	//DIO_u8_Set_Port_Direction(LCD_DATA_PORT, DIO_u8_PORT_OUTPUT);
*	DIO_u8_Set_Port_Value(LCD_DATA_PORT, Copy_u8_Command);
*
*		//ENABLE PULSE
*	//DIO_u8_Set_Pin_Direction(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8_PIN_OUTPUT);
*	DIO_u8_Set_Pin_Value(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8_PIN_HIGH);
*	_delay_ms(2);
*	DIO_u8_Set_Pin_Value(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8_PIN_LOW);
*/
LCD_void_Write(Copy_u8_Command);
}

void LCD_void_Write_Data(u8 Copy_u8_Data){
	//Set RS 1 FOR DATA
DIO_u8_Set_Pin_Value( LCD_CTRL_PORT , LCD_RS_PIN , DIO_u8_PIN_HIGH );
/*	//Set RW LOW FOR WRITE
*	//DIO_u8_Set_Pin_Direction(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8_PIN_OUTPUT);
*	DIO_u8_Set_Pin_Value(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8_PIN_LOW);
*
*		//Send DATA on Port
*	//DIO_u8_Set_Port_Direction(LCD_DATA_PORT, DIO_u8_PORT_OUTPUT);
*	DIO_u8_Set_Port_Value(LCD_DATA_PORT, Copy_u8_Data);
*
*		//ENABLE PULSE
*	//DIO_u8_Set_Pin_Direction(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8_PIN_OUTPUT);
*	DIO_u8_Set_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8_PIN_HIGH);
*	_delay_ms(2);
*	DIO_u8_Set_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8_PIN_LOW);
*/
LCD_void_Write(Copy_u8_Data);
}

void LCD_void_Innit_8Bit(void){
	// Direction Defined in main func
	//w8 for 30 ms
	_delay_ms(40);
	/*	//Function Set 0b0011NFXX RS RW zero since Send_Command
		* N For no of lines
		 * 0 1 line
		 * 1 2 lines
		 * F for font
		 * 0 5*8
		 * 1 5*11
		 */
	LCD_void_Write_Command(0b00111000);
		//w8 for 39 us	//can be removed as in the function a 2 ms delay is found
	_delay_us(50);
	/*	//Display ON/OFF Control 0b00001DCB
		* D for Display enable (screen)
		 * 0 off (disable)
		 * 1 on	 (enable)
		 * C for Cursor enable
		 * 0 off	(disable)
		 * 1 on		(enable)
		 * B for blink cursor
		 * 0 off 	(no blink)
		 * 1 on 	(blink)
		 */
	LCD_void_Write_Command(0b00001100);
		//w8 for 39 us	//can be removed
	_delay_us(50);
		//display clear	0b00000001
	LCD_void_Write_Command(1);
		//w8 for 1.53 ms
	_delay_ms(2);
		/*//Entry mode set	0b0000 01(I/D)(SH)		//not needed
		*ID is for
		 * 0
		 * 1
		 * SH is for
		 * 0
		 * 1
		 */
	LCD_void_Write_Command(0b00000110);
}


void  LCD_void_Write(u8 Copy_u8_Value){
		//RW(0)---->write
	DIO_u8_Set_Pin_Value(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8_PIN_LOW);
/*
	for(u8 i=0;i<8;i++){
		DIO_u8_Set_Pin_Value(LCD_u8_Data_Port, LCD_u8_Data_Pin_Arr[i], ( GET_BIT(Copy_u8_Value,0) ) );
	}*/
	DIO_u8_Set_Pin_Value(LCD_DATA_PORT, LCD_u8_Data_Pin_0, ( GET_BIT(Copy_u8_Value, BIT_0) ) );
	DIO_u8_Set_Pin_Value(LCD_DATA_PORT, LCD_u8_Data_Pin_1, ( GET_BIT(Copy_u8_Value, BIT_1) ) );
	DIO_u8_Set_Pin_Value(LCD_DATA_PORT, LCD_u8_Data_Pin_2, ( GET_BIT(Copy_u8_Value, BIT_2) ) );
	DIO_u8_Set_Pin_Value(LCD_DATA_PORT, LCD_u8_Data_Pin_3, ( GET_BIT(Copy_u8_Value, BIT_3) ) );

	DIO_u8_Set_Pin_Value(LCD_DATA_PORT, LCD_u8_Data_Pin_4, ( GET_BIT(Copy_u8_Value, BIT_4) ) );
	DIO_u8_Set_Pin_Value(LCD_DATA_PORT, LCD_u8_Data_Pin_5, ( GET_BIT(Copy_u8_Value, BIT_5) ) );
	DIO_u8_Set_Pin_Value(LCD_DATA_PORT, LCD_u8_Data_Pin_6, ( GET_BIT(Copy_u8_Value, BIT_6) ) );
	DIO_u8_Set_Pin_Value(LCD_DATA_PORT, LCD_u8_Data_Pin_7, ( GET_BIT(Copy_u8_Value, BIT_7) ) );

	DIO_u8_Set_Pin_Value( LCD_CTRL_PORT, LCD_E_PIN, DIO_u8_PIN_HIGH );  //Enable Pulse
	_delay_ms(1);
	DIO_u8_Set_Pin_Value( LCD_CTRL_PORT, LCD_E_PIN, DIO_u8_PIN_LOW ); //End Of PULSE
}

void LCD_void_WriteString(const char* Copy_pcString, u8 Copy_u8_XPos, u8 Copy_u8_YPos){
	if( (Copy_u8_XPos >= LCD_BIT_16) || (Copy_u8_YPos >=2) )
		 LCD_void_GoTo_DDRAMPos( LCD_BIT_0, LCD_FIRST_LINE );
	else
		LCD_void_GoTo_DDRAMPos( Copy_u8_XPos, Copy_u8_YPos );
	u8 Local_u8CURNT_POS = Copy_u8_XPos;
	u8 i=0;
		//print the string
	while(*(Copy_pcString)!='\0'){
		LCD_void_Write_Data( *(Copy_pcString) );
		Copy_pcString++;
		Local_u8CURNT_POS++;
		if(Local_u8CURNT_POS >= LCD_BIT_16){
			LCD_void_GoTo_DDRAMPos( LCD_BIT_0+i, LCD_SECOND_LINE );
			i++;
		}
	}
}


 void LCD_void_GoTo_DDRAMPos( u8 Copy_u8_XPos, u8 Copy_u8_YPos ){
	//Equation to calculate the address depending on coordinates x y
u8 Local_u8_DDRAM_Address = Copy_u8_XPos + ( (Copy_u8_YPos)*(0x40) );
	// set MSB to 1 to send command SET DDRAM ADDRESS	0b 1 ADDRESS
SET_BIT( Local_u8_DDRAM_Address, BIT_7 );
	// Send command to set starting point address
LCD_void_Write_Command(Local_u8_DDRAM_Address);

}


void LCD_void_WriteSpecialCharacter(u8* Copy_u8SpCharacPattern_Array, u8 Copy_u8SPCharNo, u8 Copy_u8_XPos, u8 Copy_u8_YPos ){
	//Equation to calculate the address depending on the block no
u8 Local_u8_CGRAM_Address = (Copy_u8SPCharNo)*8;
	// set MSB to 0 & BIT_6 to 1 ---> to send command SET CGRAM ADDRESS	0b 01 ADDRESS
//CLEAR_BIT(Local_u8_CGRAM_Address,7);	----> NOT NEEDED CUZ INITAILLY = 0
SET_BIT(Local_u8_CGRAM_Address,6);
	// Send command to set starting point address
LCD_void_Write_Command(Local_u8_CGRAM_Address);
	//Send Data for 8 bytes (CGRAM Locations) and each LOCATION HAVE 8 Bytes
	//AC (address counter) auto increment after first location is finished
for(u8 ByteNo=0; ByteNo<8; ByteNo++){
	LCD_void_Write_Data( Copy_u8SpCharacPattern_Array[ByteNo] );
	}
	//Go To Pos x ,y in Data display(DDRAM)
	LCD_void_GoTo_DDRAMPos(Copy_u8_XPos, Copy_u8_YPos);
	//Send location number to DDRAM and it will display from byte 0 to byte 7
	LCD_void_Write_Data(Copy_u8SPCharNo);

	/*	arabic
	*
	*	u8 Yarr[8]={0, 0, 1, 1, 15, 0, 5, 0};
	*	LCD_void_WriteSpecialCharacter(Yarr,0,15,0);
	*	_delay_ms(500);
	*	u8 Oarr[8]={0,0,7, 5, 7, 1, 7,0};
	*	LCD_void_WriteSpecialCharacter(Oarr,1,14,0);
	*	_delay_ms(500);
	*	u8 Sarr[8]={ 0, 21, 21, 21, 31, 0, 0,0};
	*	LCD_void_WriteSpecialCharacter(Sarr,2,13,0);
	*	_delay_ms(500);
	*	u8 _arr[8]={ 0, 0, 0, 0, 15, 0, 0,0};
	*	LCD_void_WriteSpecialCharacter(_arr,3,12,0);
	*	_delay_ms(500);
	*	u8 Farr[8]={2, 7, 5, 7, 1, 15, 0, 0};
	*	LCD_void_WriteSpecialCharacter(Farr,4,11,0);
	*	_delay_ms(500);
	*	u8 farr[8]={0, 0, 16, 16, 31, 0, 0,0};
	*	LCD_void_WriteSpecialCharacter(farr,5,10,0);
	*	_delay_ms(500);
	*/
}



void LCD_void_WriteNumber(u32 Copy_u32Number){
	/*case the number is 0*/
	if(Copy_u32Number == 0){
		LCD_void_Write_Data('0');
		return;
	}
		/*Array to save numbers in it*/
	u8 Local_NumberINArray[32]={0};
		/*variable to save and count the array elements*/
	u8 Local_ArrayPosition=0;

	while(Copy_u32Number!=0){
		/*taking the LSB of the number and saving it in the array current position*/
	u8 Local_u8LSBDigit = Copy_u32Number%10;
	Local_NumberINArray[Local_ArrayPosition]=Local_u8LSBDigit+'0';
		/*jump to next position/address*/
	Local_ArrayPosition++;
		/*remove digit added in the array from the whole Number*/
	Copy_u32Number/=10;
	}
		/*last array position is '\0' just like the string array*/
	Local_NumberINArray[Local_ArrayPosition]='\0';
		/*reverse the array as it saved backwards*/
	LCD_void_ReverseArray( Local_NumberINArray, Local_ArrayPosition );
	u8 Local_ArrayPos=0;
		/* Go to specified position of x & y if needed and add in function arguments*/
		//	LCD_void_GoTo_DDRAMPos( Copy_u8_xPos, Copy_u8_yPos );
	while(Local_NumberINArray[Local_ArrayPos]!='\0')
	{
	LCD_void_Write_Data( Local_NumberINArray[Local_ArrayPos] );
	Local_ArrayPos++;
	}
}

 void LCD_void_ReverseArray(u8* Copy_u8Array, u8 NumOfElemnts){
	for(u8 i=0;i<(NumOfElemnts/2);i++){
		u8 temp=0;
		temp=Copy_u8Array[i];
		Copy_u8Array[i]=Copy_u8Array[NumOfElemnts-1-i];
		Copy_u8Array[NumOfElemnts-1-i]=temp;
		/*
		 * void reverse (u8* ptr, u8 length){
		 * u8 start=0;
		 * u8 end = length-1;
		 * while(start<end){
		 * swap(&ptr[start],&ptr[end]);
		 * start++;
		 * end++;
		 * }
		 * }
		 */
	}
}

void LCD_void_ClearScreen(void){
	LCD_void_Write_Command(1);
	_delay_ms(2);
}
