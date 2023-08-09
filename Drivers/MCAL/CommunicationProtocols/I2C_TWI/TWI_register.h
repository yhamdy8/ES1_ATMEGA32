/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		COMPONENT: TWI						***********************/
/************************		VERSION: 1.00						***********************/
/************************		DATE: 10/07/2023					***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWI_u8TWAR	*((volatile u8*)0x22)	/* TWI(SLAVE) Address Register */ // SET OWN ADDRESS
#define TWAR_TWA6  7   /* RW,1*/
#define TWAR_TWA5  6   /* RW,1*/
#define TWAR_TWA4  5   /* RW,1*/
#define TWAR_TWA3  4   /* RW,1*/
#define TWAR_TWA2  3   /* RW,1*/
#define TWAR_TWA1  2   /* RW,1*/
#define TWAR_TWA0  1   /* RW,1*/
#define TWAR_TWGCE 0 	// ENABLE GENERAL CALL RECOGNITION


#define TWI_u8TWCR	*((volatile u8*)0x56)	/* Control Register */
#define TWCR_TWINT	7	// interrupt FLAG of TWI~if raised it set CLK to 0~,(Manually)cleared by setting it to 1
#define TWCR_TWEA	6	// EN ACK bit
#define TWCR_TWSTA	5	// TWI Start Condition Bit ~MUST be cleared by SW when start cond is transmitted~
#define TWCR_TWSTO	4	// TWI Stop Condition Flag ~Cleared Automatically~
#define TWCR_TWWC	3	// TWI write collision FLAGG
#define TWCR_TWEN	2	// TWI EN bit
#define TWCR_TWIE	0	// TWI Interrupt EN


#define TWI_u8TWSR	*((volatile u8*)0x21)	/* Status Register */
#define TWSR_TWS7	7    /* R,1,, */ // Bits used to return the last operation ID
#define TWSR_TWS6	6    /* R,1,, */ // used to check on operation done or not
#define TWSR_TWS5	5    /* R,1,, */ // Mask the prescaler bits to zero when checking the TWI status bits
#define TWSR_TWS4	4    /* R,1,, */
#define TWSR_TWS3	3    /* R,1,, */

#define TWSR_TWPS1	1	//precaler b1,, used to set the SCL freq
#define TWSR_TWPS0	0 	//precaler b0,, used to set the SCL freq


#define TWI_u8TWBR	*((volatile u8*)0x20) /* TWI BIT RATE REGISTER */ // Select SCK freq


#define TWI_u8TWDR	*((volatile u8*)0x23) /* TWI DATA REGISTER */ //elii bytkb hna hwa elii bytb3 3la el SDA BUS
#define TWDR_TWD7	7
#define TWDR_TWD6	6
#define TWDR_TWD5   5
#define TWDR_TWD4   4
#define TWDR_TWD3   3
#define TWDR_TWD2   2
#define TWDR_TWD1   1
#define TWDR_TWD0   0



#endif /* TWI_REGISTER_H_ */
