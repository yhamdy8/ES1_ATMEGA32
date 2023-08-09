/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: SPI							***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_register.h"

void SPI_voidMasterInit(void){
	/*Interrupt Disabled */
	/*Data Order MSB By default*/
	/*Clock Polarity And Clock Phase set as default*/
	/*Master Initialisation */
	SET_BIT(SPI_u8SPCR, SPCR_MSTR);
	/*Select CLK prescaler According to Slave freq	// Divby16*/
	SET_BIT(SPI_u8SPCR, SPCR_SPR0);
	CLR_BIT(SPI_u8SPCR, SPCR_SPR1);
	CLR_BIT(SPI_u8SPSR, SPSR_SPI2X);
	/* Enable SPI*/
	SET_BIT(SPI_u8SPCR, SPCR_SPE);
}

void SPI_voidSlaveInit(void){

	/*Slave Initialisation */
		CLR_BIT(SPI_u8SPCR, SPCR_MSTR);
	/* Enable SPI*/
	SET_BIT(SPI_u8SPCR, SPCR_SPE);
}

u8 SPI_u8TrasmitReceive(u8 Copy_u8Data){
	/*Send The Data*/
	SPI_u8SPDR = Copy_u8Data;
	/*Polling until Transfer is complete*/
	while( ( GET_BIT(SPI_u8SPSR, SPSR_SPIF) ) == 0);
	/*Return data*/
	return SPI_u8SPDR;

}


void __vector_12(void) __attribute__((signal));
void __vector_12(void){

}
