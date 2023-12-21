#ifndef _DET_H_
#define _DET_H_


/* !Comment: List of Modules Ids */
#define RCC_MODULE_ID       1u
#define GPIO_MODULE_ID      2u


void Det_ReportError(uint8 u8ModuleId, uint8 u8ErrorId, uint8 u8FunctionId);


#endif
