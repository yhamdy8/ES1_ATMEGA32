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

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


	/* Configuration bits section */
	// Buad rate configuration
	#define USART_Baud_Rate		9600
	// Parity mode check
	#define UART_parity_mode	0

	/* Buad rate configuration */
	#if USART_Baud_Rate ==  2400

	#define USART_u8UBRRL_Val		207
	#define USART_u8UBRRH_Val		128

	#elif USART_Baud_Rate == 4800

	#define USART_u8UBRRL_Val		103
	#define USART_u8UBRRH_Val		0

	#elif USART_Baud_Rate == 9600

	#define USART_u8UBRRL_Val		51
	#define USART_u8UBRRH_Val		0

	#elif USART_Baud_Rate == 14400

	#define USART_u8UBRRL_Val		34
	#define USART_u8UBRRH_Val		0

	#elif USART_Baud_Rate == 19200

	#define USART_u8UBRRL_Val		25
	#define USART_u8UBRRH_Val		0

	#elif USART_Baud_Rate == 38400

	#define USART_u8UBRRL_Val		12
	#define USART_u8UBRRH_Val		0

	#elif USART_Baud_Rate == 250000

	#define USART_u8UBRRL_Val		1
	#define USART_u8UBRRH_Val		0

	#else

	#define USART_u8UBRRL_Val		51
	#define USART_u8UBRRH_Val		0

	#endif

u8 UART_u8ReceiveChar(void);


void USART_voidInit(void);

void USART_voidSendChar(u16 Copy_u8Data);

u16 USART_u16ReceiveChar(void);

void UART_voidTrasmitString(u8* Copy_pStr);

void UART_u8ReceiveString(u8* Copy_u8ARecievedString);

void USART_voidSet_RXCallback(void (*copy_ptr_callback)(void));

u8 USART_voidReadDataRegister(void);


#endif /* USART_INTERFACE_H_ */
