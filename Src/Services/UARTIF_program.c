#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "UART_interface.h"


void (*UARTIF_pvCallBack) (void);

void UARTIF_passIRQ();

void UARTIFinitialize()
{
	UART_init();
	USART1_setIRQHandler(UARTIF_passIRQ);
}

void UARTIF_attachcomponentcallback(void (*pvcallback) (void))
{
	UARTIF_pvCallBack = pvcallback;
}

void UARTIF_passIRQ()
{
	UARTIF_pvCallBack();
}

void UARTIF_readData(uint8* u8recievedData)
{
	UART_udtReceiveINT(u8recievedData);
}

void UARTIF_sendData(uint8* u8dataSent)
{
	UART_udtTransmit(u8dataSent);
}

// void allocateRows(uint16 ***u16memoryAllocated, uint8 rows)
// {
//     *u16memoryAllocated = (uint16 **)calloc(rows,sizeof(uint16 *));
// }
//
// void allocateCols(uint16 **u16memoryAllocated, uint8 cols)
// {
//	 u16memoryAllocated[u8row] = (uint16 *)calloc(cols,sizeof(uint16));
// }
//
//
//
//void UARTIFProcessData()
//{
//	if (!u8Excecutionflag)
//	{
//		UART_udtReceiveINT(&u8RecievedCmnd);
//		u8Excecutionflag = ~u8Excecutionflag;
//		UART_udtTransmit((uint8 *)"ACK");
//	}
//	else
//	{
//		uint8 recieveddata;
//		switch (u8RecievedCmnd)
//		{
//			case '0':
//
//				UART_udtReceiveINT(&recieveddata);
//				allocateRows(&u16memoryAllocated, recieveddata);
//				u8Excecutionflag = ~u8Excecutionflag;
//				UART_udtTransmit((uint8 *)"ACK");
//				break;
//			case '1':
//				UART_udtReceiveINT(&recieveddata);
//				u8recordsize = recieveddata + 4;
//				allocateCols(u16memoryAllocated, recieveddata + 4);
//				u8Excecutionflag = ~u8Excecutionflag;
//				UART_udtTransmit((uint8 *)"ACK");
//				break;
//			case '2':
//				UART_udtReceiveINT(&recieveddata);
//				u16memoryAllocated[u8row][u8col++] = recieveddata;
//				if (u8col >= u8recordsize)
//				{
//					u8col = 0;
//					u8row++;
//					u8Excecutionflag = ~u8Excecutionflag;
//					UART_udtTransmit((uint8 *)"ACK");
//				}
//				break;
//		}
//	}
//}
//
//
