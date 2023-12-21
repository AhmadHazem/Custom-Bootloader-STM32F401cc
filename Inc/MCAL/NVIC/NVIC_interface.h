/*
 * NVIC_interface.h
 *
 *  Created on: Oct 2, 2023
 *      Author: BLU-RAY
 */

#ifndef _MCAL_NVIC_NVIC_INTERFACE_H_
#define _MCAL_NVIC_NVIC_INTERFACE_H_

Std_ReturnType NVIC_udtEnableInterrupt  (uint8 u8PerIndex);
Std_ReturnType NVIC_udtDisableInterrupt (uint8 u8PerIndex);
Std_ReturnType NVIC_udtSetPendingFlag   (uint8 u8PerIndex);
Std_ReturnType NVIC_udtClearPendingFlag (uint8 u8PerIndex);
Std_ReturnType NVIC_udtGetActiveFlag    (uint8 u8PerIndex, uint8* pu8ActiveFlag);
Std_ReturnType NVIC_vidSetPriority (uint8 u8PerIndex, uint8 u8Priority);
void NVIC_vidInit(void);


/* NVIC functions IDs */
#define NVIC_UDT_ENABLE_INTERRUPT    1u
#define NVIC_UDT_DISABLE_INTERRUPT   2u
#define NVIC_UDT_SET_PENDING_FLAG    3u
#define NVIC_UDT_CLEAR_PENDING_FLAG  4u
#define NVIC_UDT_GET_ACTIVE_FLAG     5u
#define NVIC_VID_SET_PRIORITY        6u

/* NVIC error IDs */
#define NVIC_INVALID_PERIPHERAL_ID   1u

#endif /* _MCAL_NVIC_NVIC_INTERFACE_H_ */
