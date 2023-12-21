/*
 * RCC_interface.h
 *
 *  Created on: Sep 11, 2023
 *      Author: BLU-RAY
 */

#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_


/* !Comment: Bus IDs */
#define AHB                   1u
#define APB1                  2u
#define APB2                  3u

/* !Comment: Clock Selection IDs */
#define RCC_HSI               1u
#define RCC_HSE_RC            2u
#define RCC_HSE_CRYSTAL       3u
#define RCC_PLL               4u

/* !Comment: */


/* !Comment: Module Public Interfaces */
Std_ReturnType RCC_udtInitSystemClock        (void);
Std_ReturnType RCC_udtDeinitSystemClock		 (void);
Std_ReturnType RCC_udtEnablePeripheralClock  (uint8 u8BusId, uint8 u8PerId);
Std_ReturnType RCC_udtDisablePeripheralClock (uint8 u8BusId, uint8 u8PerId);
Std_ReturnType RCC_udtResetPeripheral        (uint8 u8BusId, uint8 u8PerId);

#endif /* _RCC_INTERFACE_H_ */
