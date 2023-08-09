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


#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPI_u8SPCR		*((volatile u8*) 0x2D)
#define SPCR_SPIE		7	//SPI INTERRUPT ENABLE
#define SPCR_SPE		6	//SPI ENABLE
#define SPCR_DORD		5	//DATA ORDER ~MSB or LSB~
#define SPCR_MSTR		4	//MASTER/SLAVE select bit ,, 1-> MASTER
#define SPCR_CPOL		3	//CLK POLARITY,, 0-> (LEADING EDGE)Rising,, 1->(LEADING EDGE)Falling
#define SPCR_CPHA		2	//CLK PHASE   ,, 0-> (LEADING EDGE)Sample,, 1->(LEADING EDGE)Setup
#define SPCR_SPR1		1	//Clock rate Select for master (prescaler) bit 1
#define SPCR_SPR0		0	//Clock rate Select for master (prescaler) bit 0

#define SPI_u8SPSR      *((volatile u8*) 0x2E)
#define SPSR_SPIF		7	//SPI INTERRUPT FLAG
#define SPSR_WCOL		6	//Write COllison Flag
#define SPSR_SPI2X		0	//Double SPI Speed Bit

#define SPI_u8SPDR      *((volatile u8*) 0x2F)	// SPI DATA REGISTER


#endif /* SPI_REGISTER_H_ */
