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


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_interface.h"
#include "TWI_Config.h"
#include "I2C_private.h"
#include "I2C_register.h"

void TWI_voidMasterInit(u8 Assign_u8MasterAddress)
{
	/* Set Clock Frequency ,, set for 400k*/
	// Set TWBR
	TWI_u8TWBR = TWBR;
	// Set TWPS
	TWI_u8TWSR &= TWPS_MASK;
	TWI_u8TWSR |= TWPS;

	/* Enable Interrupt if wanted ,, we're function is Sync(Polling) */
	/*Check if Master wont be Addressed*/
	if( Assign_u8MasterAddress != 0 )
	{
		TWI_u8TWAR = (Assign_u8MasterAddress<<1);
	}

	/* Enable Master Generating ACK bit after receiving the data */
	SET_BIT(TWI_u8TWCR, TWCR_TWEA);

	/* Enable TWI*/
	SET_BIT(TWI_u8TWCR, TWCR_TWEN);

}

void TWI_voidSlaveInit(u8 Assign_u8SlaveAddress){
	/*Initialise Node Address*/
	TWI_u8TWAR = (Assign_u8SlaveAddress<<1);
	/* Enable TWI*/
	SET_BIT(TWI_u8TWCR, TWCR_TWEN);
}

TWI_ErrStatus TWI_SendStartCondition(void){
	TWI_ErrStatus Loc_ErrStatus = NoError;
	/* Send Start Condition*/
	SET_BIT(TWI_u8TWCR, TWCR_TWSTA);

	/* Clear the Interrupt Flag to start the previous operation */
	SET_BIT(TWI_u8TWCR, TWCR_TWINT);

	/* Waiting until the interrupt flag is raised again */
	while( ( GET_BIT(TWI_u8TWCR,TWCR_TWINT) ) == 0 );

	/*Check On status is done correctly */
	if( ( TWI_u8TWSR & TWS_MASK ) != START_ACK )
	{
		Loc_ErrStatus = StartConditionError;
	}


	return Loc_ErrStatus;
}

TWI_ErrStatus TWI_SendRepeatStart(void){
	TWI_ErrStatus Loc_ErrStatus = NoError;
	/* Send Start Condition*/
	SET_BIT(TWI_u8TWCR, TWCR_TWSTA);

	/* Clear the Interrupt Flag to start the previous operation */
	SET_BIT(TWI_u8TWCR, TWCR_TWINT);

	/* Waiting until the interrupt flag is raised again */
	while( ( GET_BIT(TWI_u8TWCR,TWCR_TWINT) ) == 0 );

	/*Check On status is done correctly */
	if( ( TWI_u8TWSR & TWS_MASK ) != REP_START_ACK )
	{
		Loc_ErrStatus = RepeatedStartCondErr;
	}


	return Loc_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAdress_Write(u8 Copy_u8SlaveAddress){
	TWI_ErrStatus Loc_ErrStatus = NoError;
	/* Clear The Start Condition Bit */
	CLR_BIT(TWI_u8TWCR, TWCR_TWSTA);

	/* Set the Slave Add in the 7 MSB in data register */
	TWI_u8TWDR = (Copy_u8SlaveAddress<<1);

	/* Clr LSB To choose Write request ~ it's zero by default since register is shifted left by 1~ */

	/* Clear the Interrupt Flag to start the previous operation */
	SET_BIT(TWI_u8TWCR, TWCR_TWINT);

	/* Waiting until the interrupt flag is raised again */
	while( ( GET_BIT(TWI_u8TWCR,TWCR_TWINT) ) == 0 );

	/*Check On status is done correctly */
	if( ( TWI_u8TWSR & TWS_MASK ) != SLAVE_ADD_AND_WR_ACK )
	{
		Loc_ErrStatus = SlaveAddressWithWRITEErr;
	}

	return Loc_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddress_Read(u8 Copy_u8SlaveAddress){
	TWI_ErrStatus Loc_ErrStatus = NoError;

	/* Clear The Start Condition Bit */
	CLR_BIT(TWI_u8TWCR, TWCR_TWSTA);

	/* Set the Slave Add in the 7 MSB in data register */
	TWI_u8TWDR = (Copy_u8SlaveAddress<<1);

	/* Set LSB To choose Read request */
	SET_BIT(TWI_u8TWDR,TWDR_TWD0);

	/* Clear the Interrupt Flag to start the previous operation */
	SET_BIT(TWI_u8TWCR, TWCR_TWINT);

	/* Waiting until the interrupt flag is raised again */
	while( ( GET_BIT(TWI_u8TWCR,TWCR_TWINT) ) == 0 );

	/*Check On status is done correctly */
	if( ( TWI_u8TWSR & TWS_MASK ) != SLAVE_ADD_AND_RD_ACK )
	{
		Loc_ErrStatus = SlaveAddressWithREADErr;
	}

	return Loc_ErrStatus;
}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte){
	TWI_ErrStatus Loc_ErrStatus = NoError;

	/*Write the Data Byte in the Data Register */
	TWI_u8TWDR = Copy_u8DataByte;

	/* Clear the Interrupt Flag to start the previous operation */
	SET_BIT(TWI_u8TWCR, TWCR_TWINT);

	/* Waiting until the interrupt flag is raised again */
	while( ( GET_BIT(TWI_u8TWCR,TWCR_TWINT) ) == 0 );

	/*Check On status is done correctly by checking the operation status */
	if( ( TWI_u8TWSR & TWS_MASK ) != MSTR_WR_BYTE_ACK )
	{
		Loc_ErrStatus = MasterWRITEByteErr;
	}

	return Loc_ErrStatus;
}

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte){
	TWI_ErrStatus Loc_ErrStatus = NoError;

	/* Clear the Interrupt Flag to start the slave sending data */
	SET_BIT(TWI_u8TWCR, TWCR_TWINT);

	/* Waiting until the interrupt flag is raised again */
	while( ( GET_BIT(TWI_u8TWCR,TWCR_TWINT) ) == 0 );

	/*Check On status is done correctly by checking the operation status */
	if( ( TWI_u8TWSR & TWS_MASK ) != MSTR_RD_BYTE_WITH_ACK ) // depend on Master respond with ACK or NACK
	{
		Loc_ErrStatus = MasterReadByteWithACKErr;
	}else
	{
		/* Read the Received Data */
		*Copy_pu8DataByte = TWI_u8TWDR;
	}

	return Loc_ErrStatus;
}

TWI_ErrStatus TWI_SendStopCondition(void){
	TWI_ErrStatus Loc_ErrStatus = NoError;

	/* Generate Stop Condition On the Bus */
	SET_BIT(TWI_u8TWCR, TWCR_TWSTO);

	/* Clear the Interrupt Flag to start the previous operation */
	SET_BIT(TWI_u8TWCR, TWCR_TWINT);

	return Loc_ErrStatus;
}
