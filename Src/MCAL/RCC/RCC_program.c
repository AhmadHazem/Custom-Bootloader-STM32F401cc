#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_utilities.h"



Std_ReturnType RCC_SelectHSI()
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	/* Enable HSI and disable HSE and PLL*/
	RCC->CR.B.HSION = STD_HIGH;
	RCC->CR.B.HSEON = STD_LOW;
	RCC->CR.B.PLLON = STD_LOW;

	/*Select HSI and deselect HSE and PLL*/
	RCC->CFGR.B.SW0 = STD_LOW;
	RCC->CFGR.B.SW1 = STD_LOW;

	/* Wait until HSI clock is Ready*/
	while(RCC->CR.B.HSIRDY == 0);
	udtReturnValue = E_OK;

	return udtReturnValue;
}


Std_ReturnType RCC_SelectHSERC()
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	//Enable HSE
	RCC->CR.B.HSION = STD_LOW;
	RCC->CR.B.HSEON = STD_HIGH;
	RCC->CR.B.PLLON = STD_LOW;

	//Select HSE
	RCC->CFGR.B.SW0 = STD_HIGH;
	RCC->CFGR.B.SW1 = STD_LOW;

	//Select RC circuit
	RCC->CR.B.HSEBYP = STD_LOW;

	//Wait till clock is stable
	while(RCC->CR.B.HSERDY == 0);
	udtReturnValue = E_OK;

	return udtReturnValue;
}

Std_ReturnType RCC_SelectHSEOSC()
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	//Enable HSE
	RCC->CR.B.HSEON = STD_HIGH;
	RCC->CR.B.HSION = STD_LOW;
	RCC->CR.B.PLLON = STD_LOW;

	//Select OSC circuit
	RCC->CR.B.HSEBYP = STD_HIGH;

	//Select HSE

	RCC->CFGR.B.SW0 = STD_HIGH;
	RCC->CFGR.B.SW1 = STD_LOW;


	//Wait till clock is stable
	while(RCC->CR.B.HSERDY == 0);
	udtReturnValue = E_OK;

	return udtReturnValue;
}

#if RCC_CLOCK_SELECTION == RCC_PLL
Std_ReturnType RCC_SelectPLL()
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	double fltDivisionResult  = (RCC_PLL_DESIRED_CLOCK / RCC_FREQ_IN);
	uint32 *fraction =(uint32 *)decimal_to_fraction(fltDivisionResult);
	if (fraction[0] < Lower_Bound_Config || fraction[0] > Mid_Bound_Config)
		return udtReturnValue;

	if (fraction[1] < Lower_Bound_Config || fraction[1] > Upper_Bound_Config)
		return udtReturnValue;

	RCC->PLLCFGR.B.PLLN = fraction[0];
	RCC->PLLCFGR.B.PLLM = fraction[1];
	RCC->PLLCFGR.B.PLLP = RCC_PLL_Presecale_Selection;

	//Enable PLL
	RCC->CR.B.HSION = STD_LOW;
	RCC->CR.B.HSEON = STD_LOW;
	RCC->CR.B.PLLON = STD_HIGH;

	//Select PLL
	RCC->CFGR.B.SW0 = STD_LOW;
	RCC->CFGR.B.SW1 = STD_HIGH;

	//Wait till clock is stable
	while(RCC->CR.B.PLLRDY == 0);
	udtReturnValue = E_OK;
	return udtReturnValue;
}
#endif

Std_ReturnType RCC_udtInitSystemClock        (void)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
#if RCC_CLOCK_SELECTION  == RCC_HSI
	udtReturnValue = RCC_SelectHSI();
#elif RCC_CLOCK_SELECTION == RCC_HSE_RC
	udtReturnValue = RCC_SelectHSERC();
#elif RCC_CLOCK_SELECTION == RCC_HSE_CRYSTAL
	udtReturnValue = RCC_SelectHSEOSC();
#elif RCC_CLOCK_SELECTION == RCC_PLL
	udtReturnValue = RCC_SelectPLL();
#else
	#error "Invalid clock selection"
#endif
	return udtReturnValue;
}


Std_ReturnType RCC_udtDeinitSystemClock		(void)
{
	RCC->CR.B.HSION = STD_ON;

	while(RCC->CR.B.HSIRDY == STD_LOW);

	RCC->CFGR.R = 0x0;

	while(RCC->CFGR.B.SWS != 0x0);

	RCC->CR.B.HSEON = STD_OFF;
	RCC->CR.B.HSEBYP = STD_OFF;
	RCC->CR.B.CSSON = STD_OFF;

	while(RCC->CR.B.HSERDY != STD_LOW);

	RCC->CR.B.PLLON = STD_OFF;

	while(RCC->CR.B.PLLRDY != STD_LOW);

	RCC->PLLCFGR.R = 0x24003010;

	return E_OK;
}

Std_ReturnType RCC_udtEnablePeripheralClock  (uint8 u8BusId, uint8 u8PerId)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	if(u8PerId <= RCC_MAX_Registers)
	{
		switch(u8BusId)
		{
			case AHB  : SET_BIT(RCC->AHB1ENR.R, u8PerId);
			            udtReturnValue = E_OK;
			            break;

			case APB1 : SET_BIT(RCC->APB1ENR.R, u8PerId);
			            udtReturnValue = E_OK;
			            break;

			case APB2 : SET_BIT(RCC->APB2ENR.R, u8PerId);
			            udtReturnValue = E_OK;
			            break;

			default   : /* !Comment: Report Error */
			            #if RCC_DET_USED == STD_ON
			            /* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_BUS_ID); */
						#endif
			            break;
		}
	}
	else
	{
		/* !Comment: Report Error */
		#if RCC_DET_USED == STD_ON
		/* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_PERIPHERAL_ID);*/
		#endif

	}
	return udtReturnValue;
}


Std_ReturnType 	RCC_udtDisablePeripheralClock  (uint8 u8BusId, uint8 u8PerId)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	if(u8PerId <= RCC_MAX_Registers)
	{
		switch(u8BusId)
		{
			case AHB  : CLR_BIT(RCC->AHB1ENR.R, u8PerId);
			            udtReturnValue = E_OK;
			            break;

			case APB1 : CLR_BIT(RCC->APB1ENR.R, u8PerId);
			            udtReturnValue = E_OK;
			            break;

			case APB2 : CLR_BIT(RCC->APB2ENR.R, u8PerId);
			            udtReturnValue = E_OK;
			            break;

			default   : /* !Comment: Report Error */
			            #if RCC_DET_USED == STD_ON
			            /* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_BUS_ID); */
						#endif
			            break;
		}
	}
	else
	{
		/* !Comment: Report Error */
		#if RCC_DET_USED == STD_ON
		/* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_PERIPHERAL_ID);*/
		#endif
	}
	return udtReturnValue ;
}


Std_ReturnType 	RCC_udtResetPeripheral  (uint8 u8BusId, uint8 u8PerId)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

		if(u8PerId <= RCC_MAX_Registers)
		{
			switch(u8BusId)
			{
				case AHB  : SET_BIT(RCC->AHB1RSTR.R, u8PerId);
				            udtReturnValue = E_OK;
				            break;

				case APB1 : SET_BIT(RCC->APB1RSTR.R, u8PerId);
				            udtReturnValue = E_OK;
				            break;

				case APB2 : SET_BIT(RCC->APB2RSTR.R, u8PerId);
				            udtReturnValue = E_OK;
				            break;

				default   : /* !Comment: Report Error */
				            #if RCC_DET_USED == STD_ON
				            /* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_BUS_ID); */
							#endif
				            break;
			}
		}
		else
		{
			/* !Comment: Report Error */
			#if RCC_DET_USED == STD_ON
			/* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_PERIPHERAL_ID);*/
			#endif
		}

		return udtReturnValue;
}
