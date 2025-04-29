/*
 * GAGHL_AVR_GPIO.h
 *
 * Created: 4/29/2025 11:54:02 PM
 *  Author: GAGHL
 */ 


#ifndef GAGHL_AVR_GPIO_H_
#define GAGHL_AVR_GPIO_H_

#include <avr/io.h>

#define HIGH 1
#define LOW  0

typedef enum{
	PA_0,PA_1,PA_2,PA_3,PA_4,PA_5,PA_6,PA_7,
	PB_0,PB_1,PB_2,PB_3,PB_4,PB_5,PB_6,PB_7,
	PC_0,PC_1,PC_2,PC_3,PC_4,PC_5,PC_6,PC_7,
	PD_0,PD_1,PD_2,PD_3,PD_4,PD_5,PD_6,PD_7,
	PE_0,PE_1,PE_2,PE_3,PE_4,PE_5,PE_6,PE_7,
	PF_0,PF_1,PF_2,PF_3,PF_4,PF_5,PF_6,PF_7
}Pin_num;

void digitalWrite(uint8_t Pin_num, uint8_t Pin_val);



#endif //GAGHL_AVR_GPIO