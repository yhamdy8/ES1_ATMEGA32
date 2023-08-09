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

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_

#define USART_u8UDR		*((volatile u8*)0x2C)	// data register

#define USART_u8UCSRA	*((volatile u8*)0x2B)	//Control registers ,, flags
#define UCSRA_RXC	7	// Receive complete flag
#define UCSRA_TXC	6	// transmission complete flag
#define UCSRA_UDRE	5	// Data register empty flag
#define UCSRA_FE	4	//frame error
#define UCSRA_DOR	3	//Data overrunn // msh la72 y2ra eldata elii btgelo
#define UCSRA_PE	2	// Parity Error
#define UCSRA_U2X	1	// Double transmission speed
#define UCSRA_MPCM	0	// multiprocessor Communication Mode "Synchronous Mode"

#define USART_u8UCSRB	*((volatile u8*)0x2A)	//Control Register
#define UCSRB_RXCIE		7	// Interrupt Enable of RXC
#define UCSRB_TXCIE		6	// Interrupt Enable of TXC
#define UCSRB_UDRIE		5	// Interrupt Enable of UDRE
#define UCSRB_RXEN		4	//Receive cct enable
#define UCSRB_TXEN		3	// transmit cct enable
#define UCSRB_UCSZ2		2	// Character ~data~ size selection bit2
#define UCSRB_RXB8		1	// Bit 8 in Receive
#define UCSRB_TXB8		0	// Bit 8 in Transmit

#define USART_u8UCSRC	*((volatile u8*)0x40)
#define UCSRC_URSEL		7	//Register select ~ =0b1xxxxxxx; ~ to select this register,, assign dont set bit
#define UCSRC_UMSEL		6	//USART Mode Select,, 0-> Asynch,, 1->Synch
#define UCSRC_UPM1		5	//Parity Mode Select b1
#define UCSRC_UPM0		4	//Parity Mode Select b0
#define UCSRC_USBS		3	// Stop Bit Select ,,0-> 1bit, 1-> 2bits
#define UCSRC_UCSZ1		2	// Character Size Selection bit1
#define UCSRC_UCSZ0		1	// Character Size Selection bit0
#define UCSRC_UCPOL		0	// Clk Polarity

#define USART_u8UBRRH	*((volatile u8*)0x40)
#define UBRRH_URSEL		7	//Register select ~ =0b0xxxxxxx; ~ to select this register,, assign dont set bit

#define USART_u8UBRRL	*((volatile u8*) 0x29)



#endif /* USART_REGISTER_H_ */
