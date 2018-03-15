/****************************************  File Info  ****************************************************
** File name:               output.h
** Descriptions:            
**
**--------------------------------------------------------------------------------------------------------
** Created by:              Vraliens
** Created date:            2018-3-15
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

#ifndef  __OUTPUT_H__
#define  __OUTPUT_H__
typedef enum
{
	TRIGGLE_SCR1, 
	TRIGGLE_SCR2, 
	TRIGGLE_SCR3, 
	TRIGGLE_SCR4,
	TRIGGLE_SCR5,
	TRIGGLE_SCR6
}TRIGGLE_PORT;

void Output_Init(void);

void Output_Triggle_Set(TRIGGLE_PORT SCRx);
void Output_Triggle_Clear(TRIGGLE_PORT SCRx);

void Output_Run_Relay(bool status);
void Output_Fault_Relay(bool status);

#endif