/*
 * UARTTP_interface.h
 *
 *  Created on: Dec 2, 2023
 *      Author: BLU-RAY
 */

#ifndef SERVICES_UARTTP_INTERFACE_H_
#define SERVICES_UARTTP_INTERFACE_H_


void UARTIFinitialize();
void UARTIF_attachcomponentcallback(void (*pvcallback) (void));
void UARTIF_readData(uint8* u8recievedData);
void UARTIF_sendData(uint8* u8dataSent);

#endif /* SERVICES_UARTTP_INTERFACE_H_ */
