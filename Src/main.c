
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "Bootloader_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"



int main()
{
	// Choose RCC clock and Initialize
	RCC_udtInitSystemClock();

	// Enable GPIOA peripheral
	RCC_udtEnablePeripheralClock(AHB, 0);

	// Initialize GPIO
	GPIO_Init();

	// Enable UART Global Interrupt
	NVIC_udtEnableInterrupt(37);

	// Enable Clock for UART peripheral
	RCC_udtEnablePeripheralClock(APB2, 4);

	// Initialize Bootloader
	Bootloader_init();

	// Bootloader Send Ready to Host
	Bootloader_sendmsg("RDY", 500);

	while(!Bootloader_JUMPFlag)
	{

	}

	NVIC_udtDisableInterrupt(37);

	RCC_udtDisablePeripheralClock(APB2, 4);
	RCC_udtDisablePeripheralClock(AHB, 0);

	RCC_udtDeinitSystemClock();


	Bootloader_sendack();
	//Execute APP
	Bootloader_ExcecuteApp();


}
