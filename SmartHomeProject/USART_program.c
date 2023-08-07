/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: USART						***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_register.h"

#define UART_enable	1
#define UART_disable 0
#define UART_UCSRC_mask		0b10000000
#define UART_UCSZ_val		3
#define UART_parity_mode	0


//static u8* UART_copy_ptr_str = NULL;

void (*UART_Rx_callback)(void) = NULL;


/*
void USART_voidInit(void){

	// Select 9600 Baud rate ~9600 bit/second~
		USART_u8UBRRL = 51;	// from Table page164
	/*
	 * 	 u8 Loc_u8UCSRCValue=0;
	// Select UCSRC 1->bit7
	SET_BIT(Loc_u8UCSRCValue, UCSRC_UMSEL);
	// Select Asynchronous Mode
	SET_BIT(Loc_u8UCSRCValue, UCSRC_UMSEL);
	//No Parity Mode ,, Disabled by default
	//1 stop Bit	// by default 1 stop bit
	// Set Character Size ,, by default Set to 8
	SET_BIT(Loc_u8UCSRCValue, UCSRC_UCSZ1);
	SET_BIT(Loc_u8UCSRCValue, UCSRC_UCSZ0);
	// assign the value to the register
	USART_u8UCSRC = Loc_u8UCSRCValue;

		//Enable TX,RX
	SET_BIT(USART_u8UCSRB, UCSRB_RXEN);
	SET_BIT(USART_u8UCSRB, UCSRB_TXEN);
	/////////////////////////////////////////////////


	USART_u8UCSRB = ((UART_enable << UCSRB_RXCIE) | (UART_enable << UCSRB_TXCIE) | (UART_disable << UCSRB_UDRIE) | (UART_enable << UCSRB_RXEN) | (UART_enable << UCSRB_TXEN) | (UART_disable << UCSRB_UCSZ2) | (UART_disable));

	USART_u8UCSRC = (UART_UCSRC_mask | (UART_disable << UCSRC_UMSEL) | (UART_parity_mode << UCSRC_UPM0) | (UART_disable << UCSRC_USBS) | (UART_UCSZ_val << UCSRC_UCSZ0) | (UART_disable << UCSRC_UCPOL));
}
*/
void USART_voidInit(void){
	USART_u8UBRRL = 51;
	USART_u8UBRRH = USART_u8UBRRH_Val;
	USART_u8UBRRL = USART_u8UBRRL_Val;
	USART_u8UCSRB = ((UART_enable << UCSRB_RXCIE) | (UART_enable << UCSRB_TXCIE) | (UART_disable << UCSRB_UDRIE) | (UART_enable << UCSRB_RXEN) | (UART_enable << UCSRB_TXEN) | (UART_disable << UCSRB_UCSZ2) | (UART_disable));
	USART_u8UCSRC = (UART_UCSRC_mask | (UART_disable << UCSRC_UMSEL) | (UART_parity_mode << UCSRC_UPM0) | (UART_disable << UCSRC_USBS) | (UART_UCSZ_val << UCSRC_UCSZ0) | (UART_disable << UCSRC_UCPOL));
}

u8 USART_voidReadDataRegister(void)
{
	return USART_u8UDR;
}

void USART_voidSendChar(u16 Copy_u8Data){
	//polling until transmit buffer is empty
	while( (GET_BIT(USART_u8UCSRA, UCSRA_UDRE) ) == 0);
	USART_u8UDR = Copy_u8Data;
}

u16 USART_u16ReceiveChar(void){
	//polling till the receive is complete
	while( (GET_BIT(USART_u8UCSRA, UCSRA_RXC) ) == 0);
	return USART_u8UDR;
}

void UART_voidTrasmitString(u8* Copy_pStr){
	while(*Copy_pStr != '\0'){
		USART_voidSendChar(*Copy_pStr);
		Copy_pStr++;
	}
	USART_voidSendChar('\0');
}

void UART_u8ReceiveString(u8* Copy_u8ARecievedString){
	*Copy_u8ARecievedString=USART_u16ReceiveChar();
	while(*Copy_u8ARecievedString != '\0'){
		Copy_u8ARecievedString++;
		*Copy_u8ARecievedString=USART_u16ReceiveChar();
	}
}


void USART_voidSet_RXCallback(void (*copy_ptr_callback)(void)){
	/*
	 *
	 */
	UART_Rx_callback = copy_ptr_callback;
}



// UART, Rx complete
void __vector_13(void){
	/*
	 *
	 */
		if(UART_Rx_callback != NULL){
			UART_Rx_callback();
	}
}

// USART Data Register Empty
void __vector_14(void){
	/*
	 *
	 */

}

// UART, Tx complete
void __vector_15(void){
	/*
	 *
	 */
//	UART_void_transmit_str(UART_copy_ptr_str);
}
