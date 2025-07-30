/**
 * @file GAGHL_AVR_GPIO.h
 * @brief This file contains the declarations of functions and macros for controlling the GPIO pins.
 * 
 * This header file provides the basic functions for configuring pin modes, 
 * reading from and writing to the GPIO pins on AVR microcontrollers.
 * 
 * Created: 4/29/2025 11:54:02 PM
 * Author: GAGHL
 */

/*
 * This project is licensed under the Creative Commons Attribution-NonCommercial 4.0 International License (CC BY-NC 4.0).
 * 
 * You are free to:
 * - Share: Copy and redistribute the material in any medium or format.
 * - Adapt: Remix, transform, and build upon the material.
 * 
 * The following conditions apply:
 * - Attribution: You must give appropriate credit, provide a link to the license, and indicate if changes were made.
 * - NonCommercial: You may not use the material for commercial purposes.
 * 
 * Full license text: https://creativecommons.org/licenses/by-nc/4.0/legalcode
 */

#ifndef GAGHL_AVR_GPIO_H_
#define GAGHL_AVR_GPIO_H_

#include <avr/io.h>

#if defined(__AVR_ATmega32__)
	#define MICRO_TYPE "ATmega32"
#elif defined(__AVR_ATmega328P__)
	#define MICRO_TYPE "ATmega328"
#else
	#define MICRO_TYPE "Unknown"
#endif

#define INPUT         0
#define OUTPUT        1
#define INPUT_PULLUP  2
#define LOW           0
#define HIGH          1

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum pin_t
 * @brief Enum for representing pins on different ports (A-G).
 * 
 * The pins are numbered from 0 to 55, representing the available GPIO pins on the AVR.
 * The ports are divided into groups: PA_0 to PA_7, PB_0 to PB_7, etc.
 */
typedef enum {
	PA_0,PA_1,PA_2,PA_3,PA_4,PA_5,PA_6,PA_7,
	PB_0,PB_1,PB_2,PB_3,PB_4,PB_5,PB_6,PB_7,
	PC_0,PC_1,PC_2,PC_3,PC_4,PC_5,PC_6,PC_7,
	PD_0,PD_1,PD_2,PD_3,PD_4,PD_5,PD_6,PD_7,
	PE_0,PE_1,PE_2,PE_3,PE_4,PE_5,PE_6,PE_7,
	PF_0,PF_1,PF_2,PF_3,PF_4,PF_5,PF_6,PF_7
} pin_t;

void pinMode(pin_t pin, uint8_t pinModeVal);

void digitalWrite(pin_t pin, uint8_t pinValue);

void digitalToggle(pin_t pin);

void digitalPWM(pin_t pin, uint8_t duty_cycle);

int8_t digitalRead(pin_t pin);

int8_t digitalReadPort(pin_t pin);


#ifdef __cplusplus
}
#endif

#endif //GAGHL_AVR_GPIO