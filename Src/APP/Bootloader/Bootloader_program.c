/*
 * Bootloader_program.c
 *
 *  Created on: Dec 5, 2023
 *      Author: BLU-RAY
 */
#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FLS_interface.h"
#include "SYSTICK_interface.h"
#include "UARTIF_interface.h"
#include "Bootloader_interface.h"

uint32 jumpAddress;

/*Bootloader flags*/
uint8 Bootloader_ACKFlag = BL_IDLE;
uint8 Bootloader_FlashFlag = BL_FLS_OFF;
uint8 Bootloader_BYTESFLAG = BL_BYTES_OFF;
uint8 Bootloader_JUMPFlag = STD_OFF;
uint8 Bootloader_REPFlag = STD_OFF;
uint8 Bootloader_checksum = 0;

/*Bootloader Data in memory*/
uint8** u8data;
uint8 u8cols = 0;
uint8 u8row = 0;
uint8 u8col = 0;

void Bootloader_ProcessData();

void Bootloader_init()
{
	SYSTICK_vidInit();
	UARTIFinitialize();
	UARTIF_attachcomponentcallback(Bootloader_ProcessData);
}

void allocateRows(uint8 ***u8data, uint8 rows)
{
    *u8data = (uint8 **)calloc(rows,sizeof(uint8 *));
}

void allocateCols(uint8 **u8data, uint16 cols)
{
	 if (cols % 2 == 1)
	 {
		 cols++;
	 }
	 u8data[u8row] = (uint8 *)calloc(cols,sizeof(uint8));
}

void Bootloader_reteriveData(uint8*** data)
{
	*data = u8data;
}


Std_ReturnType Bootloader_write()
{
	uint32 u32InitialAddress;
	uint8 EOF = STD_LOW;
	uint8 AppID = BL_APP2;
	uint8 u8row = 0;
	while(1)
	{
		if (EOF)
			break;

		uint8 u8recordsize = u8data[u8row][0];
		uint16 offsetAddress = ((uint16)u8data[u8row][1] << 8) + u8data[u8row][2];
		uint8 u8formatType = u8data[u8row][3];
		uint16 u16data[u8recordsize/2];
		uint8 u8counter = 0;
		for (; u8counter < u8recordsize; u8counter += 2)
		{
			u16data[u8counter/2] = ((uint16)u8data[u8row][4 + u8counter] << 8) + u8data[u8row][5 + u8counter];
		}

		if (u8recordsize % 2 == 1)
		{
			u16data[u8counter] = ((uint16)u8data[u8row][4 + u8counter - 1] << 8);
		}
		switch(u8formatType)
		{
			case 0:

				uint32 u32Address = u32InitialAddress + offsetAddress;
				FLS_WriteSector(AppID, u32Address, u16data, u8recordsize/2);
				break;

			case 1:
				EOF = STD_HIGH;
				break;

			case 4:
				u32InitialAddress = ((uint32)u16data[0] << 16) ;
				if(!FLS_GetAddressSectorID(u32InitialAddress + ((uint16)u8data[1][1] << 8), &AppID))
				{
					AppID = BL_APP2;
				}

				FLS_EraseSector(AppID);
				break;

			case 5:
				jumpAddress = u32InitialAddress + ((uint16)u8data[1][1] << 8) + u8data[1][2];
			default:
				return E_NOT_OK;
		}
		u8row++;

	}
	return E_OK;
}


Std_ReturnType Bootloader_MassErase()
{
	return FLS_MassErase();
}

Std_ReturnType Bootloader_AppErase(uint8 AppID)
{
	if (AppID > BL_APP5)
	{
		return E_NOT_OK;
	}

	return 	FLS_EraseSector(AppID);
}

void Bootloader_ExcecuteApp()
{
	uint32 u32MainStackPointer = *((volatile uint32*)jumpAddress);
	uint32 u32ResetHandlerAddress = *((volatile uint32*)(jumpAddress + 4));

	void (*resetHandler_Address)(void) = (void *)u32ResetHandlerAddress;

	register uint32 __regMainStackPointer     __asm("sp");
	__regMainStackPointer = u32MainStackPointer;

	resetHandler_Address();
}


void Bootloader_sendmsg(u8msg msg, uint16 timeoutInMilliSeconds)
{
	while(Bootloader_ACKFlag != BL_ACK)
	{
		UARTIF_sendData(msg);
		SYSTICK_udtSynchMsecondsDelay(timeoutInMilliSeconds);
	}
	Bootloader_ACKFlag = BL_IDLE;
}

Std_ReturnType Bootloader_sendack()
{
	UARTIF_sendData((uint8*)"ACK");
	return E_OK;
}

Std_ReturnType Bootloader_sendnack()
{
	UARTIF_sendData((uint8*)"NACK");
	return E_OK;
}

void Bootloader_ProcessData()
{
	uint8 u8recievedItem;
	static uint8 u8recievedCmnd;
	static uint16 u16memsize = 0;
	static uint8 u8recordsize;

	if (Bootloader_FlashFlag == BL_FLS_ON)
	{

		switch(u8recievedCmnd)
		{
			case BL_ALLOC_MEM:
				UARTIF_readData(&u8recievedItem);
				u16memsize += u8recievedItem;
				allocateRows(&u8data, u16memsize);
				Bootloader_FlashFlag = BL_FLS_OFF;
				Bootloader_sendack();
				break;
			case BL_ALLOC_REC:
				UARTIF_readData(&u8recievedItem);
				u8recordsize = u8recievedItem + 5;
				allocateCols(u8data, u8recordsize);
				Bootloader_sendack();
				Bootloader_FlashFlag = BL_FLS_OFF;
				break;
			case BL_SAVE_DATA:
				UARTIF_readData(&u8recievedItem);
				u8data[u8row][u8cols++] = u8recievedItem ;
				if (u8cols >= u8recordsize)
				{
					u8cols = 0;
					uint8 checksum = ~Bootloader_checksum;
					if ((checksum+1) == u8data[u8row][u8recordsize - 1])
					{
						u8row++;
						Bootloader_checksum = 0;
						Bootloader_FlashFlag = BL_FLS_OFF;
						Bootloader_sendack();
					}
					else
					{
						Bootloader_sendnack();
					}
				}
				else
				{
					Bootloader_checksum += u8recievedItem;
					Bootloader_sendack();
				}
				break;
		}
	}
	else
	{
		UARTIF_readData(&u8recievedItem);
		switch(u8recievedItem >> 4)
		{
			case BL_ACK:
				Bootloader_ACKFlag = BL_ACK;
				break;
			case BL_NACK:
				Bootloader_ACKFlag = BL_NACK;
				break;
			case BL_CMD:
				Bootloader_FlashFlag = BL_FLS_ON;
				u8recievedCmnd = u8recievedItem & 0x0F;
				Bootloader_sendack();
				break;
			case BL_FLASH_DATA:
				Bootloader_write();
				u16memsize = 0;
				Bootloader_sendack();
				break;
			case BL_EXCUTE_APP:
				Bootloader_JUMPFlag = STD_ON;
				break;
			case BL_ERASE_CHIP:
				Bootloader_MassErase();
				break;
			case BL_ERASE_APP0:
			case BL_ERASE_APP1:
			case BL_ERASE_APP2:
			case BL_ERASE_APP3:
			case BL_ERASE_APP4:
				Bootloader_AppErase(u8recievedItem-4);
				Bootloader_FlashFlag = BL_FLS_OFF;
				Bootloader_sendack();
				break;

		}
	}
}




