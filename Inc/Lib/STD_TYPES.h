/*
 * STD_TYPES.h
 *
 *  Created on: Sep 4, 2023
 *      Author: BLU-RAY
 */

#ifndef _LIB_STD_TYPES_H_
#define _LIB_STD_TYPES_H_


typedef 	unsigned char 			uint8;
typedef 	unsigned short			uint16;
typedef 	unsigned int			uint32;
typedef 	unsigned long			uint64;

#define		STD_HIGH				1u
#define		STD_LOW					0u

#define		STD_ON					1u
#define 	STD_OFF					0u

#define     BIT0					0u
#define     BIT1					1u
#define     BIT2					2u
#define     BIT3					3u
#define     BIT4					4u
#define     BIT5					5u
#define     BIT6					6u
#define     BIT7					7u
#define     BIT8					8u
#define     BIT9					9u
#define     BIT10					10u
#define     BIT11					11u
#define     BIT12					12u
#define     BIT13					13u
#define     BIT14					14u
#define     BIT15					15u
#define     BIT16					16u
#define     BIT17					17u
#define     BIT18					18u
#define     BIT19					19u
#define     BIT20					20u
#define     BIT21					21u
#define     BIT22					22u
#define     BIT23					23u
#define     BIT24					24u
#define     BIT25					25u
#define     BIT26					26u
#define     BIT27					27u
#define     BIT28					28u
#define     BIT29					29u
#define     BIT30					30u
#define     BIT31					31u


/* !Comment: Error states */
typedef enum
{
	E_OK = 1,
	E_NOT_OK = 0,
	E_PENDING = 2
}Std_ReturnType;


#define 	STD_ON					1u
#define		STD_OFF					0u


#endif /* _LIB_STD_TYPES_H_ */
