/*
 * GPIO_private.h
 *
 *  Created on: Sep 7, 2023
 *      Author: BLU-RAY
 */

#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

/* !Comment: Port definitions */
#define GPIO_PORTA    1u
#define GPIO_PORTB    2u
#define GPIO_PORTC    3u

/* !Comment: Pin definitions */
#define GPIO_PIN0     0u
#define GPIO_PIN1     1u
#define GPIO_PIN2     2u
#define GPIO_PIN3     3u
#define GPIO_PIN4     4u
#define GPIO_PIN5     5u
#define GPIO_PIN6     6u
#define GPIO_PIN7     7u
#define GPIO_PIN8     8u
#define GPIO_PIN9     9u
#define GPIO_PIN10    10u
#define GPIO_PIN11    11u
#define GPIO_PIN12    12u
#define GPIO_PIN13    13u
#define GPIO_PIN14    14u
#define GPIO_PIN15    15u

/* !Comment: Pin values */
#define GPIO_HIGH     1u
#define GPIO_LOW      0u

/* !Comment: GPIO functions IDs */
#define GPIO_INIT_ID                     1u
#define GPIO_UDT_SET_PIN_VALUE_ID        2u
#define GPIO_UDT_GET_PIN_VALUE_ID        3u
#define GPIO_UDTATOMICSETPINVALUE_ID     4u
#define GPIO_UDTUNLOCKPINCONFIG_ID       5u
#define GPIO_UDTLOCKPINCONFIG_ID         6u

/* !Comment: GPIO Errors IDs */
#define GPIO_INVALID_PORT_ID             1u
#define GPIO_INVALID_PIN_STATE           2u
#define GPIO_INVALID_PIN_ID              3u

/* !Comment:Max Pins */
#define GPIO_LOWER_PINS_NUMBERS			 8u
#define GPIO_UPPER_PINS_NUMBERS			 16u

typedef struct
{
	uint32 MODER;
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
}GPIO_type;


#define GPIOA ((GPIO_type*)0x40020000u)
#define GPIOB ((GPIO_type*)0x40020400u)
#define GPIOC ((GPIO_type*)0x40020800u)



#define NOT_USED  255u


typedef enum
{
	GPIO_INPUT,
	GPIO_OUTPUT,
	GPIO_AF,
	GPIO_ANALOG
}GPIO_MODES_E;

typedef enum
{
	GPIO_PUSH_PULL,
	GPIO_OPEN_DRAIN
}GPIO_OTYPE_E;

/* !Comment: GPIO port output speed register (GPIOx_OSPEEDR) */
typedef enum
{
	GPIO_LOW_SPEED,
	GPIO_MEDIUM_SPEED,
	GPIO_HIGH_SPEED,
	GPIO_VHIGH_SPEED
}GPIO_OSPEED_E;

/* !Comment: GPIO port pull-up/pull-down register (GPIOx_PUPDR) */
typedef enum
{
	GPIO_FLOATING,
	GPIO_PULL_UP,
	GPIO_PULL_DOWN
}GPIO_INPUT_E;

typedef enum
{
	 GPIO_AF0,
	 GPIO_AF1,
	 GPIO_AF2,
	 GPIO_AF3,
	 GPIO_AF4,
	 GPIO_AF5,
	 GPIO_AF6,
	 GPIO_AF7,
	 GPIO_AF8,
	 GPIO_AF9,
	 GPIO_AF10,
	 GPIO_AF11,
	 GPIO_AF12,
	 GPIO_AF13,
	 GPIO_AF14,
	 GPIO_AF15
}GPIO_ALTERNATIVE_FUNCTION_E;

/* !Comment: GPIO pin configurations */
typedef struct
{
	uint8 u8PortId;
	uint8 u8PinId;

	GPIO_MODES_E udtMode;
	GPIO_OTYPE_E udtType;
	GPIO_OSPEED_E udtSpeed;
	GPIO_INPUT_E udtInputState;
	GPIO_ALTERNATIVE_FUNCTION_E udtAlternativeFunction;

}GPIO_pinState;


#endif /* _GPIO_PRIVATE_H_ */
