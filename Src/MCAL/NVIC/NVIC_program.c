#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DET.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"


void NVIC_vidInit(void)
{
	#define SCB_AIRCR  *((volatile uint32*)0xE000ED0C)
	SCB_AIRCR = NVIC_GROUP_4_SUB_0;
}

Std_ReturnType NVIC_vidSetPriority (uint8 u8PerIndex, uint8 u8Priority)
{
	Std_ReturnType udtRetVal = E_NOT_OK;

	if(u8PerIndex > 84)
	{
#if NVIC_DET_USED
		Det_ReportError(NVIC_MODULE_ID, NVIC_VID_SET_PRIORITY, NVIC_INVALID_PERIPHERAL_ID);
#endif
	}
	else
	{
		NVIC->IPR[u8PerIndex] = u8Priority;

		udtRetVal = E_OK;
	}

	return udtRetVal;
}

Std_ReturnType NVIC_udtEnableInterrupt (uint8 u8PerIndex)
{
	Std_ReturnType udtRetVal = E_NOT_OK;

	if(u8PerIndex > 84)
	{
#if NVIC_DET_USED
		Det_ReportError(NVIC_MODULE_ID, NVIC_UDT_ENABLE_INTERRUPT, NVIC_INVALID_PERIPHERAL_ID);
#endif
	}
	else
	{
		NVIC -> ISER[u8PerIndex / 32] = (1 << (u8PerIndex % 32));

		udtRetVal = E_OK;
	}

	return udtRetVal;
}

Std_ReturnType NVIC_udtDisableInterrupt (uint8 u8PerIndex)
{
	Std_ReturnType udtRetVal = E_NOT_OK;

	if(u8PerIndex > 84)
	{
#if NVIC_DET_USED
		Det_ReportError(NVIC_MODULE_ID, NVIC_UDT_DISABLE_INTERRUPT, NVIC_INVALID_PERIPHERAL_ID);
#endif
	}
	else
	{
		NVIC -> ICER[u8PerIndex / 32] = (1 << (u8PerIndex % 32));

		udtRetVal = E_OK;
	}

	return udtRetVal;
}

Std_ReturnType NVIC_udtSetPendingFlag   (uint8 u8PerIndex)
{
	Std_ReturnType udtRetVal = E_NOT_OK;

	if(u8PerIndex > 84)
	{
#if NVIC_DET_USED
		Det_ReportError(NVIC_MODULE_ID, NVIC_UDT_SET_PENDING_FLAG, NVIC_INVALID_PERIPHERAL_ID);
#endif
	}
	else
	{
		NVIC -> ISPR[u8PerIndex / 32] = (1 << (u8PerIndex % 32));

		udtRetVal = E_OK;
	}

	return udtRetVal;
}

Std_ReturnType NVIC_udtClearPendingFlag (uint8 u8PerIndex)
{
	Std_ReturnType udtRetVal = E_NOT_OK;

	if(u8PerIndex > 84)
	{
#if NVIC_DET_USED
		Det_ReportError(NVIC_MODULE_ID, NVIC_UDT_CLEAR_PENDING_FLAG, NVIC_INVALID_PERIPHERAL_ID);
#endif
	}
	else
	{
		NVIC -> ICPR[u8PerIndex / 32] = (1 << (u8PerIndex % 32));

		udtRetVal = E_OK;
	}

	return udtRetVal;
}

Std_ReturnType NVIC_udtGetActiveFlag    (uint8 u8PerIndex, uint8* pu8ActiveFlag)
{
	Std_ReturnType udtRetVal = E_NOT_OK;

	if(u8PerIndex > 84)
	{
#if NVIC_DET_USED
		Det_ReportError(NVIC_MODULE_ID, NVIC_UDT_GET_ACTIVE_FLAG, NVIC_INVALID_PERIPHERAL_ID);
#endif
	}
	else
	{
		*pu8ActiveFlag = GET_BIT((NVIC -> IABR[u8PerIndex / 32]),(1 << (u8PerIndex % 32)));

		udtRetVal = E_OK;
	}

	return udtRetVal;
}
