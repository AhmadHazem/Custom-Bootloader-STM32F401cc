/*
 * BIT_MATH.h
 *
 *  Created on: Sep 4, 2023
 *      Author: BLU-RAY
 */

#ifndef _LIB_BIT_MATH_H_
#define _LIB_BIT_MATH_H_


#define 	SET_BIT(VAR, BIT)    	VAR |=  (1 << BIT)
#define 	CLR_BIT(VAR, BIT)    	VAR &= ~(1 << BIT)
#define 	TOG_BIT(VAR, BIT)    	VAR ^=  (1 << BIT)
#define 	GET_BIT(VAR, BIT)    	((VAR >> BIT ) & 1)


#endif /* _LIB_BIT_MATH_H_ */
