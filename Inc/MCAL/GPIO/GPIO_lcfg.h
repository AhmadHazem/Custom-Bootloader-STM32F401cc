/*
 * GPIO_lcfg.h
 *
 *  Created on: Sep 8, 2023
 *      Author: BLU-RAY
 */

#ifndef _GPIO_LCFG_H_
#define _GPIO_LCFG_H_



#define GPIO_NUMBER_OF_USED_PIN  2u
extern GPIO_pinState  GPIO_udtArrayOfPins [GPIO_NUMBER_OF_USED_PIN];

Std_ReturnType GPIO_Assign_to_output_Pin(uint8 PortID, uint8 PinID,GPIO_OTYPE_E Output_type);
Std_ReturnType GPIO_Assign_to_input_Pin(uint8 PortID, uint8 PinID, GPIO_INPUT_E Input_type);
Std_ReturnType GPIO_Assign_to_Alternative_Function(uint8 PortID, uint8 PinID, GPIO_ALTERNATIVE_FUNCTION_E alternativeFunctionSelection);

#endif /* _GPIO_LCFG_H_ */
