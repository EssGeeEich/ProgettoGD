/*
 * io_manager.h
 *
 *  Created on: Mar 2, 2023
 *      Author: david
 */

#ifndef INC_IO_MANAGER_H_
#define INC_IO_MANAGER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l4xx_hal.h"

#include "../../Drivers\BSP\B-L475E-IOT01\stm32l475e_iot01_tsensor.h"
#include "../../Drivers\BSP\B-L475E-IOT01\stm32l475e_iot01_hsensor.h"
#include "../../Drivers\BSP\B-L475E-IOT01\stm32l475e_iot01_psensor.h"

typedef enum MappedFunction{
	MF_undefined = 0,
	MF_Button,
	MF_led1,
	MF_COUNT
}MF;

typedef enum bspFunction{
	BSP_humidity = 0,
	BSP_temperature,
	BSP_pressure,
	BSP_COUNT
}bspF;

struct IOS_Man_type{
	GPIO_TypeDef * m_type;
	uint16_t m_pin;
	double m_factor;
	double m_offset;
};


void bspFunctionInit();
float bspGetValue(bspF);

void setMappedFunction(MF mf,GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,double offset,double factor);

void setDigital(MF mf,GPIO_PinState state);

GPIO_PinState readDigital(MF mf);

float readAnalog(MF mf);

#ifdef __cplusplus
}
#endif

#endif /* INC_IO_MANAGER_H_ */
