/*
 * FLS_program.c
 *
 *  Created on: Nov 29, 2023
 *      Author: BLU-RAY
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FLS_private.h"
#include "FLS_interface.h"

const uint32 SECTORS_ADDRESSES[] = {SECTOR_ADDRESS1, SECTOR_ADDRESS2, SECTOR_ADDRESS3, SECTOR_ADDRESS4, SECTOR_ADDRESS5, SECTOR_ADDRESS6};
const uint32 SECTORS_MAXSIZES[] = {SECTOR1_MAXSIZE1, SECTOR1_MAXSIZE2, SECTOR1_MAXSIZE3, SECTOR1_MAXSIZE4, SECTOR1_MAXSIZE5, SECTOR1_MAXSIZE6};

Std_ReturnType FLS_MassErase(void)
{
	// Control Register Unlocking
	FLS->KEYR = KEY1;
	FLS->KEYR = KEY2;

	// Check BSY Flag
	while(FLS->SR.B.BSY == ISBSY);

	// Activate Mass Erase Bit
	FLS->CR.B.MER = STD_ON;

	// Start Erasing
	FLS->CR.B.STRT = STD_ON;

	// Wait for the BSY Flag
	while(FLS->SR.B.BSY == ISBSY);

	// Lock Back the Control Register
	//FLS->CR.B.LOCK = STD_HIGH;

	return E_OK;
}

Std_ReturnType FLS_EraseSector(u8flsSectorID u8sectorID)
{
	// Control Register Unlocking
	FLS->KEYR = KEY1;
	FLS->KEYR = KEY2;

	// Check BSY Flag
	while(FLS->SR.B.BSY == ISBSY);

	// Activate Sector Erase Bit
	FLS->CR.B.SER = STD_ON;

	// Select Sector to be Erased
	FLS->CR.B.SNB = u8sectorID;

	// Start Erasing
	FLS->CR.B.STRT = STD_ON;

	// Wait for the BSY Flag
	while(FLS->SR.B.BSY == ISBSY);

	// Lock Back the Control Register
	FLS->CR.B.LOCK = STD_HIGH;

	return E_OK;
}

Std_ReturnType FLS_WriteSector(uint8 u8sectorID, uint32 u32sectorAddress, uint16* u16data, uint8 dataSize)
{
	Std_ReturnType u8Status = E_NOT_OK;
	uint8 u8DataCounter = 0;
	if(SECTORS_MAXSIZES[u8sectorID] > dataSize)
	{
		// Control Register Unlocking
		FLS->KEYR = KEY1;
		FLS->KEYR = KEY2;

		// Check BSY Flag
		while(FLS->SR.B.BSY == ISBSY);

		// Set Programming Flag
		FLS->CR.B.PG = STD_ON;

		// Select Program Parallelism for writing half word
		FLS->CR.B.PSIZE = FLS_PROG_HALFWORD;

		for(; u8DataCounter < dataSize ; u8DataCounter++)
		{
			uint16 temp = (u16data[u8DataCounter] << 8) + (u16data[u8DataCounter] >> 8);
			*((uint16*)u32sectorAddress) = temp;
			u32sectorAddress += 2;

			// Check BSY Flag
			while(FLS->SR.B.BSY == ISBSY);
		}

		// Lock Back the Control Register
		FLS->CR.B.LOCK = STD_HIGH;

		// Change status to ok
		u8Status = E_OK;

	}

	return u8Status;

}

Std_ReturnType FLS_ReadSector(uint8 u8sectorID, uint16* u16DataRecieved)
{
	// Allocate Necessary Space
	uint8 u8DataCounter = 0;
	uint32 u32SectorAddress = SECTORS_ADDRESSES[u8sectorID];
	for(;u8DataCounter < SECTORS_MAXSIZES[u8sectorID]; u8DataCounter++)
	{
		u16DataRecieved[u8DataCounter] = *((uint16*)u32SectorAddress);
		u32SectorAddress += 2;
	}

	return E_OK;

}

Std_ReturnType FLS_GetVersion(uint32* u32Version)
{
	uint8 u8DataCounter = 0;
	uint32 u32SectorAddress = SECTORS_ADDRESSES[0];
	*u32Version = *((uint32*)u32SectorAddress);
	return E_OK;
}

Std_ReturnType FLS_GetAddressSectorID(uint32 u32Address, uint8* SectorID)
{
	uint8 u8sectorID = 0;
	for(; u8sectorID < sizeof(SECTORS_ADDRESSES)/sizeof(uint32); u8sectorID++)
	{
		if (u32Address == SECTORS_ADDRESSES[u8sectorID])
		{
			*SectorID = u8sectorID;
			return E_OK;

		}
	}
	return E_NOT_OK;
}
