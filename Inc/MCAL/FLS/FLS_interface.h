/*
 * FLS_interface.h
 *
 *  Created on: Nov 29, 2023
 *      Author: BLU-RAY
 */

#ifndef _MCAL_FLS_FLS_INTERFACE_H_
#define _MCAL_FLS_FLS_INTERFACE_H_

typedef 	uint8		u8flsSectorID;




Std_ReturnType FLS_MassErase(void);
Std_ReturnType FLS_EraseSector(uint8 SectorID);
Std_ReturnType FLS_WriteSector(uint8 u8sectorID,uint32 u32sectorAddress, uint16* u16data, uint8 dataSize);
Std_ReturnType FLS_GetVersion(uint32* u16DataRecieved);
Std_ReturnType FLS_GetAddressSectorID(uint32 u32Address, uint8* SectorID);
Std_ReturnType FLS_ReadSector(uint8 u8sectorID, uint16* u16DataRecieved);

#endif /* _MCAL_FLS_FLS_INTERFACE_H_ */
