/*
 * FLS_private.h
 *
 *  Created on: Nov 29, 2023
 *      Author: BLU-RAY
 */

#ifndef _MCAL_FLS_PRIVATE_H_
#define _MCAL_FLS_PRIVATE_H_


/* Flash Memory Sectors */

// Flash Interface Register Struct //
typedef struct
{
	union
	{
		uint32 R;
		struct
		{
			uint32	LATENCY		:4;
			uint32	Reserved0	:4;
			uint32	PRFTEN		:1;
			uint32	ICEN		:1;
			uint32	DCEN		:1;
			uint32	ICRST		:1;
			uint32	DCRST		:1;
			uint32	Reserved1	:19;
		}B;
	}ACR;


	uint32 KEYR;

	uint32 OPTKEYR;

	union
	{
		uint32	R;
		struct
		{
			uint32	EOP			:1;
			uint32	OPERR		:1;
			uint32	Reserved0	:2;
			uint32	WRPERR		:1;
			uint32	PGAERR		:1;
			uint32	PGPERR		:1;
			uint32	PGSERR		:1;
			uint32	RDERR		:1;
			uint32	Reserved1	:7;
			uint32	BSY			:1;
			uint32	Reserved2	:15;
		}B;
	}SR;

	union
	{
		uint32	R;
		struct
		{
			uint32	PG			:1;
			uint32	SER			:1;
			uint32	MER			:1;
			uint32	SNB			:4;
			uint32	Reserved0	:1;
			uint32	PSIZE		:2;
			uint32	Reserved1	:6;
			uint32	STRT		:1;
			uint32	Reserved2	:7;
			uint32	EOPIE		:1;
			uint32	ERRIE		:1;
			uint32	Reserved3	:5;
			uint32	LOCK		:1;
		}B;
	}CR;

	union
	{
		uint32	R;
		struct
		{
			uint32	OPTLOCK		:1;
			uint32	OPTSTRT		:1;
			uint32	BOR_LEV		:2;
			uint32	Reserved0	:1;
			uint32	WDGSW		:1;
			uint32	nRSTSTOP	:1;
			uint32	nRSTSTDBY	:1;
			uint32	RDP			:8;
			uint32	nWRP		:6;
			uint32	nWRP1		:2;
			uint32	Reserved1	:7;
			uint32	SPRMOD		:1;
		}B;
	}OPTCR;
}FLS_type;

#define 	FLS				((volatile FLS_type*)0x40023C00u)

extern const uint32 SECTORS_ADDRESSES[];
extern const uint32 SECTORS_MAXSIZES[];


/*FLS KEY VALUE*/
#define		KEY1				0x45670123
#define		KEY2				0xCDEF89AB

/*FLS SECTOR IDs*/
#define		SECTOR_ID0			(u8flsSectorID(0x0))
#define		SECTOR_ID1			(u8flsSectorID(0x1))
#define		SECTOR_ID2			(u8flsSectorID(0x2))
#define		SECTOR_ID3			(u8flsSectorID(0x3))
#define		SECTOR_ID4			(u8flsSectorID(0x4))
#define		SECTOR_ID5			(u8flsSectorID(0x5))

/*FLS SECTOR STARTING ADDRESSES*/
#define		SECTOR_ADDRESS1		(0x08000000u)
#define		SECTOR_ADDRESS2		(0x08004000u)
#define		SECTOR_ADDRESS3		(0x08008000u)
#define		SECTOR_ADDRESS4		(0x0800C000u)
#define		SECTOR_ADDRESS5		(0x08010000u)
#define		SECTOR_ADDRESS6		(0x08020000u)

/*FLS MAX SIZE OF EACH SECTOR*/
#define		SECTOR1_MAXSIZE1 	(0x4000u)
#define		SECTOR1_MAXSIZE2 	(0x4000u)
#define		SECTOR1_MAXSIZE3 	(0x4000u)
#define		SECTOR1_MAXSIZE4 	(0x4000u)
#define		SECTOR1_MAXSIZE5 	(0x10000u)
#define		SECTOR1_MAXSIZE6 	(0x20000u)

/*Program Parallelism Selection*/
#define		FLS_PROG_BYTE		0x0
#define		FLS_PROG_HALFWORD	0x1
#define		FLS_PROG_WORD		0x2
#define		FLS_PROG_DOUBLEWORD 0x3

/*FLS Miscellaneous Definitions*/
#define		ISBSY			0x1u

#endif /* _MCAL_FLS_FLS_PRIVATE_H_ */
