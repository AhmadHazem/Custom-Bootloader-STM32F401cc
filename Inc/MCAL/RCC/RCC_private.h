/*
 * RCC_private.h
 *
 *  Created on: Sep 11, 2023
 *      Author: BLU-RAY
 */

#ifndef MCAL_RCC_PRIVATE_H_
#define MCAL_RCC_PRIVATE_H_


typedef struct
{
	/* !Comment: CR register */
	union
	{
		uint32 R;
		struct
		{
			uint32 HSION 	: 1;
			uint32 HSIRDY	: 1;
			uint32 Reserved1: 1;
			uint32 HSITRIM  : 5;
			uint32 HSICAL	: 8;
			uint32 HSEON	: 1;
			uint32 HSERDY	: 1;
			uint32 HSEBYP	: 1;
			uint32 CSSON	: 1;
			uint32 Reserved2: 4;
			uint32 PLLON	: 1;
			uint32 PLLRDY	: 1;
			uint32 PLLI2SON : 1;
			uint32 PLI2SRDY : 1;
			uint32 Reserved3: 4;
		}B;
	}CR;

	/* !Comment: PLLCFGR register */
	union
	{
		uint32 R;
		struct
		{
			uint32 PLLM		:6;
			uint32 PLLN		:9;
			uint32 Reserved1:1;
			uint32 PLLP		:2;
			uint32 Reserved2:4;
			uint32 PLLSRC	:1;
			uint32 Reserved3:1;
			uint32 PLLQ		:4;
			uint32 Reserved4:4;
		}B;
	}PLLCFGR;

	/* !Comment: CFGR register */
	union
	{
		uint32 R;
		struct
		{
			uint32 SW0			:1;
			uint32 SW1			:1;
			uint32 SWS			:2;
			uint32 HPRE			:4;
			uint32 Reserved1	:2;
			uint32 PPRE1		:3;
			uint32 PPRE2		:3;
			uint32 RTCPRE		:5;
			uint32 MCO1			:2;
			uint32 I2SSCR		:1;
			uint32 MCO1PRE		:3;
			uint32 MCO2PRE		:3;
			uint32 MCO2			:2;
		}B;
	}CFGR;



	/* !Comment: CIR register */
	union
	{
		uint32 R;
		struct
		{
			uint32 LSIRDYF		:1;
			uint32 LSERDYF		:1;
			uint32 HSIRDYF		:1;
			uint32 HSERDYF		:1;
			uint32 PLLRDYF		:1;
			uint32 PLLI2SRDYF	:1;
			uint32 Reserved1	:1;
			uint32 CSSF			:1;
			uint32 LSIRDYIE		:1;
			uint32 LSERDYIE		:1;
			uint32 HSIRDYIE		:1;
			uint32 HSERDYIE		:1;
			uint32 PLLRDYIE		:1;
			uint32 PLLI2SRDYIE	:1;
			uint32 Reserved2	:2;
			uint32 LSIRDYC		:1;
			uint32 LSERDYC		:1;
			uint32 HSIRDYC		:1;
			uint32 HSERDYC		:1;
			uint32 PLLRDYC		:1;
			uint32 PLLI2SRDYC	:1;
			uint32 Reserved3	:1;
			uint32 CSSC			:1;
			uint32 Reserved4	:8;

		}B;
	}CIR;

	/* !Comment: AHB1RSTR register */
	union
	{
		uint32 R;
		struct
		{
			uint32 GPIOARST		:1;
			uint32 GPIOBRST		:1;
			uint32 GPIOCRST		:1;
			uint32 GPIODRST		:1;
			uint32 GPIOERST		:1;
			uint32 Reserved2	:2;
			uint32 GPIOHRST		:1;
			uint32 Reserved3	:4;
			uint32 CRCRST		:1;
			uint32 Reserved4	:8;
			uint32 DMA1RST		:1;
			uint32 DMA2RST		:1;
			uint32 Reserved5	:9;
		}B;
	}AHB1RSTR;

	/* !Comment: AHB2RSTR register */
	union
	{
		uint32 R;
		struct
		{
			uint32 Reserved1	:7;
			uint32 OTGFSRST		:1;
			uint32 Reserved2	:24;
		}B;

	}AHB2RSTR;


	uint32 RESERVED1;
	uint32 RESERVED2;

	/* !Comment : APB1RSTR */
	union
	{
		uint32 R;
		struct
		{
			uint32 TIM2RST		:1;
			uint32 TIM3RST		:1;
			uint32 TIN4RST		:1;
			uint32 TIM5RST		:1;
			uint32 Reserved1	:7;
			uint32 WWDGRST		:1;
			uint32 Reserved2	:2;
			uint32 SPI2RST		:1;
			uint32 SPI3RST		:1;
			uint32 Reserved3	:1;
			uint32 USART2RST	:1;
			uint32 Reserved4	:3;
			uint32 I2C1RST		:1;
			uint32 I2C2RST		:1;
			uint32 I2C3RST		:1;
			uint32 Reserved5	:4;
			uint32 PWRRST		:1;
			uint32 Reserved6	:3;
		}B;
	}APB1RSTR;

	/* !Comment : APB2RSTR */
	union
	{
		uint32 R;
		struct
		{
			uint32 TIM1RST		:1;
			uint32 Reserved1	:3;
			uint32 USART1RST	:1;
			uint32 USART6RST	:1;
			uint32 Reserved2	:2;
			uint32 ADC1RST		:1;
			uint32 Reserved3	:2;
			uint32 SDIORST		:1;
			uint32 SPI1RST		:1;
			uint32 SP4RST		:1;
			uint32 SYSCFGRST	:1;
			uint32 Reserved4	:1;
			uint32 TIM9RST		:1;
			uint32 TIM1ORST		:1;
			uint32 TIM11RST		:1;
			uint32 Reserved5	:13;
		}B;
	}APB2RSTR;

	uint32 RESERVED3;
	uint32 RESERVED4;

	/* !Comment : AHB1ENR */
	union
	{
		uint32 R;
		struct
		{
			uint32 GPIOAEN		:1;
			uint32 GPIOBEN		:1;
			uint32 GPIOCEN		:1;
			uint32 GPIODEN		:1;
			uint32 GPIOEEN		:1;
			uint32 Reserved2	:2;
			uint32 GPIOHEN		:1;
			uint32 Reserved3	:4;
			uint32 CRCEN		:1;
			uint32 Reserved4	:8;
			uint32 DMA1EN		:1;
			uint32 DMA2EN		:1;
			uint32 Reserved5	:9;
		}B;
	}AHB1ENR;


	/* !Comment : AHB2ENR */
	union
	{
		uint32 R;
		struct
		{
			uint32 Reserved1	:7;
			uint32 OTGFSEN		:1;
			uint32 Reserved2	:24;
		};
	}AHB2ENR;

	uint32 RESERVED5;
	uint32 RESERVED6;

	/* !Comment : APB1ENR */
	union
	{
		uint32 R;
		struct
		{
			uint32 TIM2EN		:1;
			uint32 TIM3EN		:1;
			uint32 TIN4EN		:1;
			uint32 TIM5EN		:1;
			uint32 Reserved1	:7;
			uint32 WWDGEN		:1;
			uint32 Reserved2	:2;
			uint32 SPI2EN		:1;
			uint32 SPI3EN		:1;
			uint32 Reserved3	:1;
			uint32 USART2EN		:1;
			uint32 Reserved4	:3;
			uint32 I2C1EN		:1;
			uint32 I2C2EN		:1;
			uint32 I2C3EN		:1;
			uint32 Reserved5	:4;
			uint32 PWREN		:1;
			uint32 Reserved6	:3;
		}B;
	}APB1ENR;

	/* !Comment : APB2ENR */
	union
	{
		uint32 R;
		struct
		{
			uint32 TIM1EN		:1;
			uint32 Reserved1	:3;
			uint32 USART1EN		:1;
			uint32 USART6EN		:1;
			uint32 Reserved2	:2;
			uint32 ADC1EN		:1;
			uint32 Reserved3	:2;
			uint32 SDIOEN		:1;
			uint32 SPI1EN		:1;
			uint32 SP4EN		:1;
			uint32 SYSCFGEN		:1;
			uint32 Reserved4	:1;
			uint32 TIM9EN		:1;
			uint32 TIM1OEN		:1;
			uint32 TIM11EN		:1;
			uint32 Reserved5	:13;
		}B;
	}APB2ENR;

	uint32 RESERVED7;
	uint32 RESERVED8;

	/* !Comment : AHB1LPENR */
	union
	{
		uint32 R;
		struct
		{
			uint32 GPIOALPEN	:1;
			uint32 GPIOBLPEN	:1;
			uint32 GPIOCLPEN	:1;
			uint32 GPIODLPEN	:1;
			uint32 GPIOELPEN	:1;
			uint32 Reserved1	:2;
			uint32 GPIOHLPEN	:1;
			uint32 Reserved2	:4;
			uint32 CRCLPEN		:1;
			uint32 Reserved3	:2;
			uint32 FLITFLPEN	:1;
			uint32 SRAMLPEN		:1;
			uint32 Reserved4	:4;
			uint32 DMA1LPEN		:1;
			uint32 DMA2LPEN		:1;
			uint32 Reserved5	:9;
		}B;
	}AHB1LPENR;


	/* !Comment : AHB2LPENR */
	union
	{
		uint32 R;
		struct
		{
			uint32 Reserved1	:7;
			uint32 OTGFSLPEN	:1;
			uint32 Reserved2	:24;
		};
	}AHB2LPENR;

	uint32 RESERVED9;
	uint32 RESERVED10;

	/* !Comment : APB1LPENR */
	union
	{
		uint32 R;
		struct
		{
			uint32 TIM2LPEN		:1;
			uint32 TIM3LPEN		:1;
			uint32 TIN4LPEN		:1;
			uint32 TIM5LPEN		:1;
			uint32 Reserved1	:7;
			uint32 WWDGLPEN		:1;
			uint32 Reserved2	:2;
			uint32 SPI2LPEN		:1;
			uint32 SPI3LPEN		:1;
			uint32 Reserved3	:1;
			uint32 USART2LPEN	:1;
			uint32 Reserved4	:3;
			uint32 I2C1LPEN		:1;
			uint32 I2C2LPEN		:1;
			uint32 I2C3LPEN		:1;
			uint32 Reserved5	:4;
			uint32 PWRLPEN		:1;
			uint32 Reserved6	:3;
		}B;
	}APB1LPENR;

	/* !Comment : APB2LPENR */
	union
	{
		uint32 R;
		struct
		{
			uint32 TIM1LPEN		:1;
			uint32 Reserved1	:3;
			uint32 USART1LPEN	:1;
			uint32 USART6LPEN	:1;
			uint32 Reserved2	:2;
			uint32 ADC1LPEN		:1;
			uint32 Reserved3	:2;
			uint32 SDIOLPEN		:1;
			uint32 SPI1LPEN		:1;
			uint32 SP4LPEN		:1;
			uint32 SYSCFGLPEN	:1;
			uint32 Reserved4	:1;
			uint32 TIM9LPEN		:1;
			uint32 TIM1OLPEN	:1;
			uint32 TIM11LPEN	:1;
			uint32 Reserved5	:13;
		}B;
	}APB2LPENR;

	uint32 RESERVED11;
	uint32 RESERVED12;

	/* !Comment : BDCR register */
	union
	{
		uint32 R;
		struct
		{
			uint32 LSEON		:1;
			uint32 LSEREDY		:1;
			uint32 LSEBYP		:1;
			uint32 Reserved1	:5;
			uint32 RTCSEL		:2;
			uint32 Reserved2	:5;
			uint32 RTCEN		:1;
			uint32 BDRST		:1;
			uint32 Reserved3	:15;
		}B;
	}BDCR;

	/* !Comment : CSR register */
	union
	{
		uint32 R;
		struct
		{
			uint32 LSION		:1;
			uint32 LSIRDY		:1;
			uint32 Reserved1	:21;
			uint32 RMVF			:1;
			uint32 BORRSTF		:1;
			uint32 PINRSTF		:1;
			uint32 PORRSTF		:1;
			uint32 SFTRSTF		:1;
			uint32 IDWGRSTF		:1;
			uint32 WWDGRSTF		:1;
			uint32 LPWRRSTF		:1;
		}B;
	}CSR;

	uint32 RESERVED13;
	uint32 RESERVED14;

	/* !Comment : SSCGR register */
	union
	{
		uint32 R;
		struct
		{
			uint32 MODPER		:13;
			uint32 INCSTEP		:15;
			uint32 Reserved		:2;
			uint32 SPREADSEL	:1;
			uint32 SSCGEN		:1;
		}B;
	}SSCGR;

	/* !Comment : PLLI2SCFGR register */
	union
	{
		uint32 R;
		struct
		{
			uint32 Reserved1	:6;
			uint32 PLLI2S0		:9;
			uint32 Reserved2	:13;
			uint32 PLLI2SR		:3;
			uint32 Reserved3	:1;
		}B;
	}PLLI2SCFGR;

	uint32 RESERVED15;

	/* !Comment : DCKCFGR register */
	union
	{
		uint32 R;
		struct
		{
			uint32 Reserved1	:24;
			uint32 TIMPRE		:1;
			uint32 Reserved2	:7;
		}B;
	}DCKCFGR;

}RCC_type;


/* !Comment: Defining RCC pointer */
#define RCC  ((volatile RCC_type*)0x40023800u)

/* !Comment : max peripheral id for each bus */
#define 	RCC_MAX_Registers   ((uint8)31u)
#define		Lower_Bound_Config	3u
#define		Upper_Bound_Config	432u
#define		Mid_Bound_Config	63u

/* !Comment: Clock Selection Functions */
Std_ReturnType RCC_SelectHSI  (void);
Std_ReturnType RCC_SelectHSERC  (void);
Std_ReturnType RCC_SelectHSEOSC  (void);
Std_ReturnType RCC_SelectPLL  (void);

#endif /* MCAL_RCC_PRIVATE_H_ */
