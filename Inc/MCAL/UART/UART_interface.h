/*
 * UART_interface.h
 *
 *  Created on: Nov 14, 2023
 *      Author: BLU-RAY
 */

#ifndef _MCAL_UART_INTERFACE_H_
#define _MCAL_UART_INTERFACE_H_

void UART_init();
void UART_udtReceive (uint8* pu8ReceivedData);
void UART_udtTransmitByte(uint8 u8Data);
void USART1_setIRQHandler(void (*pvcallback) (void));
void UART_udtReceiveINT (uint8* pu8ReceivedData);
Std_ReturnType UART_udtTransmit (uint8* pu8Data);

#endif /* _MCAL_UART_INTERFACE_H_ */
