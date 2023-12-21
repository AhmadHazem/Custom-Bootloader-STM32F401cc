/*
 * RCC_config.h
 *
 *  Created on: Sep 4, 2023
 *      Author: BLU-RAY
 */

#ifndef _RCC_CONFIG_H_
#define _RCC_CONFIG_H_

/** !Comment:
 *      Options =
 *                 RCC_HSI
 *	               RCC_HSE_RC
 *                 RCC_HSE_CRYSTAL
 *	               RCC_PLL
 */
#define 	RCC_CLOCK_SELECTION    			RCC_HSE_CRYSTAL



#define 	RCC_DET_USED           			STD_ON

/** !Comment: Write Input freq. here if (EXT. Or INT.)*/
#define 	RCC_FREQ_IN                     25000000UL



#if RCC_CLOCK_SELECTION == RCC_PLL
#define 	RCC_PLL_SOURCE                  RCC_HSE
#define 	RCC_PLL_DESIRED_CLOCK			84000000UL
#if RCC_PLL_SOURCE == RCC_HSE
    #if RCC_FREQ_IN > 26000000UL
    #error "definition error of RCC_FREQ_IN"
    #endif
#endif

/** !Comment:
 *      Options =
 *                 RCC_PLLP_Prescale_2
 *	               RCC_PLLP_Prescale_4
 *                 RCC_PLLP_Prescale_6
 *	               RCC_PLLP_Prescale_8
 */
#define		RCC_PLL_Presecale_Selection		RCC_PLLP_Prescale_2

#if RCC_PLL_SOURCE == RCC_HSI
    #if RCC_FREQ_IN > 16000000UL
    #error "definition error of RCC_FREQ_IN"
    #endif
#endif
#endif
#endif /* RCC_CLOCK_SELECTION */






