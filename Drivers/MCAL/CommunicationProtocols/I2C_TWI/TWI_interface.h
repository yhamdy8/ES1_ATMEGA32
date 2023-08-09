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

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
	NoError,StartConditionError,
	RepeatedStartCondErr,
	SlaveAddressWithWRITEErr,
	SlaveAddressWithREADErr,
	MasterWRITEByteErr,
	MasterReadByteWithACKErr,

}TWI_ErrStatus;

/*
 *  Pass 0 in the MasterAddress Argument if the master wont be addressed
 */
void TWI_voidMasterInit(u8 Assign_u8MasterAddress);

void TWI_voidSlaveInit(u8 Assign_u8SlaveAddress);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatStart(void);

TWI_ErrStatus TWI_SendSlaveAdress_Write(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddress_Read(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte);

TWI_ErrStatus TWI_SendStopCondition(void);


#endif /* TWI_INTERFACE_H_ */
