#ifndef _SYSTICK_CONFIG_H_
#define _SYSTICK_CONFIG_H_


/* !Comment: options: SYSTICK_AHB
 *                    SYSTICK_AHB_DIV_8
 */
#define 	SYSTICK_CLOCK_SOURCE    				SYSTICK_AHB_DIV_8
#define 	SYSTICK_EXCEPTION_REQUEST_ASSERTION		STD_OFF
#define 	SYSTEM_CLOCK_FREQ						25000000UL

#if (SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV_8)
#define		SYSTICK_CLOCK_FREQ						(SYSTEM_CLOCK_FREQ/8)
#else
#define		SYSTICK_CLOCK_FREQ						(SYSTEM_CLOCK_FREQ)
#endif

#endif
