/*
 * GPIO_lcfg.c
 *
 *  Created on: Sep 11, 2023
 *      Author: BLU-RAY
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_lcfg.h"

GPIO_pinState  GPIO_udtArrayOfPins [GPIO_NUMBER_OF_USED_PIN] =
{
		[0] =
		{
				.u8PortId = GPIO_PORTA,
				.u8PinId= GPIO_PIN9,
				.udtMode = GPIO_AF,
				.udtType = NOT_USED,
				.udtSpeed  = NOT_USED,
				.udtInputState = NOT_USED,
				.udtAlternativeFunction = GPIO_AF7
		},

		[1] =
		{
				.u8PortId = GPIO_PORTA,
				.u8PinId= GPIO_PIN10,
				.udtMode = GPIO_AF,
				.udtType = NOT_USED,
				.udtSpeed  = NOT_USED,
				.udtInputState = NOT_USED,
				.udtAlternativeFunction = GPIO_AF7
		}
};

