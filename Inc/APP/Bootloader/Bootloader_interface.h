/*
 * Bootloader_interface.h
 *
 *  Created on: Dec 5, 2023
 *      Author: BLU-RAY
 */

#ifndef APP_BOOTLOADER_INTERFACE_H_
#define APP_BOOTLOADER_INTERFACE_H_

/*APP ID*/
#define		BL_APP1			0u
#define		BL_APP2			1u
#define		BL_APP3			2u
#define		BL_APP4			3u
#define		BL_APP5			4u
#define		BL_APP6			5u

/*Bootloader Command or Data*/
#define		BL_FLS_ON		1u
#define		BL_FLS_OFF		0u

/*Bootloader size checker flag*/
#define		BL_BYTES_ON		1u
#define		BL_BYTES_OFF	0u

/*Bootloader Responses and State*/
#define		BL_ACK			0x1u
#define		BL_NACK			0x2u
#define		BL_IDLE			0x5u
#define		BL_REPEAT		0x4u
#define		BL_CMD			0x3u

/*Bootloader Unique Commands*/
#define		BL_SEND_VERSION 0x0u
#define		BL_ALLOC_MEM	0x1u
#define		BL_ALLOC_REC	0x2u
#define		BL_GET_VERSION	0x3u
#define		BL_ERASE_CHIP	0x8u
#define		BL_ERASE_APP0	0x4u
#define		BL_ERASE_APP1	0x5u
#define		BL_ERASE_APP2	0x6u
#define		BL_ERASE_APP3	0x7u
#define		BL_ERASE_APP4	0x9u
#define		BL_SAVE_DATA	0xAu
#define		BL_READ_FLASH	0xBu
#define		BL_FLASH_DATA	0xDu
#define		BL_EXCUTE_APP	0xEu

typedef		uint8*		u8msg;

void Bootloader_init();
void Bootloader_reteriveData(uint8*** data);
Std_ReturnType Bootloader_write();
Std_ReturnType Bootloader_MassErase();
Std_ReturnType Bootloader_AppErase(uint8 AppID);
void Bootloader_ExcecuteApp();

extern uint8 Bootloader_JUMPFlag;

#endif /* APP_BOOTLOADER_INTERFACE_H_ */
