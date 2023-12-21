#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DET.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void (*USART_pvCallBack) (void);
//uint8 receivedData[162][21]={0};
//uint8 c = 0;
//uint8 u = 0;
void UART_init()
{

//	double baudRate = UART_FREQUENCY_CLOCK/(16.0 * BAUDRATE);
//	double diff = (baudRate - (int)baudRate)*16.0;
//	uint8 div = ((diff - (int)(diff)) >= 0.5) ? (int)(diff) + 1 : (int)(diff);

	UART->BRR.B.DIV_Mantissa = 0xD;//(div >= 16) ? ((short)baudRate) + 1 : (short)baudRate;
	UART->BRR.B.DIV_Fraction = 0x9;//div;
	UART->CR1.B.UE = STD_ON;
	UART->CR1.B.TE = STD_ON;
	UART->CR1.B.RE = STD_ON;
	UART->CR1.B.RXNEIE = STD_ON;

}

void UART_udtReceive (uint8* pu8ReceivedData)
{
	*pu8ReceivedData = 0u;
    while((UART->SR.B.RXNE == 0)){}

	if(*pu8ReceivedData == 0u)
	{
		*pu8ReceivedData = UART->DR;
	}
	UART->SR.B.RXNE = 0;
}

void UART_udtReceiveINT (uint8* pu8ReceivedData)
{
	*pu8ReceivedData = UART->DR;
}

void UART_udtTransmitByte(uint8 u8Data)
{
	UART -> DR = u8Data;
    while(UART->SR.B.TXE == 0);
    UART->SR.B.TXE = 0;
}

Std_ReturnType UART_udtTransmit (uint8* pu8Data)
{
	Std_ReturnType udtRetVal = E_NOT_OK;

	uint8 u8LocalCounter = 0u;

	while(pu8Data[u8LocalCounter] != '\0')
	{
		UART_udtTransmitByte(pu8Data[u8LocalCounter++]);
	}

	return udtRetVal;
}

void USART1_setIRQHandler(void (*pvcallback) (void))
{
	USART_pvCallBack = pvcallback;
}

void USART1_IRQHandler()
{
//	UART_udtReceiveINT(&receivedData[u][c++]);
//	if (c > (receivedData[u][0] + 4))
//	{
//		receivedData[u][c] = '\0';
//		c = 0;
//		u++;
//		UART_udtTransmit((uint8 *)"ACK");
//	}
	USART_pvCallBack();
}
