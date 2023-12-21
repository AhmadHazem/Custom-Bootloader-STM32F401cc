/*
 * NVIC_private.h
 *
 *  Created on: Oct 2, 2023
 *      Author: BLU-RAY
 */

#ifndef _MCAL_NVIC_NVIC_PRIVATE_H_
#define _MCAL_NVIC_NVIC_PRIVATE_H_

typedef struct
{

	uint32 ISER[32];
	uint32 ICER[32];
	uint32 ISPR[32];
	uint32 ICPR[32];
	uint32 IABR[64];
	uint8  IPR[59];
	uint32 Reserved[580];
	uint32 STIR;
}NVIC_type;


#define NVIC    ((volatile NVIC_type*)0xE000E100)
#define SCB_AIRCR  *((volatile uint32*)0xE000ED0C)

#define NVIC_GROUP_4_SUB_0     0x05FA0300
#define NVIC_GROUP_3_SUB_1     0x05FA0400
#define NVIC_GROUP_2_SUB_2     0x05FA0500
#define NVIC_GROUP_1_SUB_3     0x05FA0600
#define NVIC_GROUP_0_SUB_4     0x05FA0700

#endif /* _MCAL_NVIC_NVIC_PRIVATE_H_ */
