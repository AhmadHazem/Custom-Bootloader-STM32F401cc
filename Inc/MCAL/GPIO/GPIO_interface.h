/*
 * GPIO_interface.h
 *
 *  Created on: Sep 8, 2023
 *      Author: BLU-RAY
 */

#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_


/* Module Public Interfaces */
void GPIO_Init (void);

Std_ReturnType GPIO_udtSetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 u8Value);
Std_ReturnType GPIO_udtGetPinValue(uint8 u8PortId, uint8 u8PinId, uint8* pu8PinValue);
Std_ReturnType GPIO_udtTogglePin(uint8 u8PortId, uint8 u8PinId);

Std_ReturnType GPIO_udtAtomicSetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 u8Value);

Std_ReturnType GPIO_udtLockPinConfig(uint8 u8PortId, uint8 u8PinId);
Std_ReturnType GPIO_udtUnlockPinConfig(uint8 u8PortId, uint8 u8PinId);




#endif /* _GPIO_INTERFACE_H_ */
