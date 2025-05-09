/*
 * GAGHL_AVR_GPIO.c
 *
 * Created: 4/29/2025 11:58:00 PM
 *  Author: GAGHL
 */ 

#include "GAGHL_AVR_GPIO.h"


/**
 * @brief  Set the pin mode (INPUT, OUTPUT, or INPUT_PULLUP) for a specific pin.
 * 
 * This function configures the pin as either an Output, Input with Pull-Up, or just an input.
 * It modifies the relevant port registers for the specific pin.
 *
 * @param   pin       The pin number (0 to 55) that will be configured.
 *                    Pins from different ports (PORTA, PORTB, etc.) are handled differently.
 * @param   pinModeVal  The desired mode for the pin (INPUT, OUTPUT, INPUT_PULLUP).
 * 
 * @return  None
 */
void pinMode(pin_t pin, uint8_t pinModeVal){
	#ifdef DDRA
	if(pin<=7){                                                  //PORTA
		if(pinModeVal==OUTPUT){
			DDRA |= (1<<pin);
		}else if(pinModeVal==INPUT_PULLUP){
			DDRA &= ~(1<<pin);
			PORTA |= (1<<pin);
		}else{
			DDRA &= ~(1<<pin);
			PORTA &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef DDRB
	else if(pin>=8 && pin<=15){                              //PORTB
		pin-=8;
		if(pinModeVal==OUTPUT){
			DDRB |= (1<<pin);
		}else if(pinModeVal==INPUT_PULLUP){
			DDRB &= ~(1<<pin);
			PORTB |= (1<<pin);
		}else{
			DDRB &= ~(1<<pin);
			PORTB &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef DDRC
	else if(pin>=16 && pin<=23){                              //PORTC
		pin-=16;
		if(pinModeVal==OUTPUT){
			DDRC |= (1<<pin);
		}else if(pinModeVal==INPUT_PULLUP){
			DDRC &= ~(1<<pin);
			PORTC |= (1<<pin);
		}else{
			DDRC &= ~(1<<pin);
			PORTC &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef DDRD
	else if(pin>=24 && pin<=31){                              //PORTD
		pin-=24;
		if(pinModeVal==OUTPUT){
			DDRD |= (1<<pin);
		}else if(pinModeVal==INPUT_PULLUP){
			DDRD &= ~(1<<pin);
			PORTD |= (1<<pin);
		}else{
			DDRD &= ~(1<<pin);
			PORTD &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef DDRE
	else if(pin>=32 && pin<=39){                              //PORTE
		pin-=32;
		if(pinModeVal==OUTPUT){
			DDRE |= (1<<pin);
		}else if(pinModeVal==INPUT_PULLUP){
			DDRE &= ~(1<<pin);
			PORTE |= (1<<pin);
		}else{
			DDRE &= ~(1<<pin);
			PORTE &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef DDRF
	else if(pin>=40 && pin<=47){                              //PORTF
		pin-=40;
		if(pinModeVal==OUTPUT){
			DDRF |= (1<<pin);
		}else if(pinModeVal==INPUT_PULLUP){
			DDRF &= ~(1<<pin);
			PORTF |= (1<<pin);
		}else{
			DDRF &= ~(1<<pin);
			PORTF &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef DDRG
	else if(pin>=48 && pin<=55){                              //PORTG
		pin-=48;
		if(pinModeVal==OUTPUT){
			DDRG |= (1<<pin);
		}else if(pinModeVal==INPUT_PULLUP){
			DDRG &= ~(1<<pin);
			PORTG |= (1<<pin);
		}else{
			DDRG &= ~(1<<pin);
			PORTG &= ~(1<<pin);
		}
	}
	#endif
}

/**
 * @brief  Write a HIGH or LOW value to a specific pin.
 * 
 * This function sets the output value of the specified pin to HIGH or LOW. 
 * It modifies the corresponding port register to set the output state.
 *
 * @param   pin       The pin number (0 to 55) that will be written to.
 * @param   pinValue  The value to write to the pin (HIGH or LOW).
 * 
 * @return  None
 */
void digitalWrite(pin_t pin, uint8_t pinValue){
	#ifdef PORTA
	if(pin<=7){                                                 //PORTA
		if(pinValue){
			PORTA |= (1<<pin);
		}else{
			PORTA &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef PORTB
	else if(pin>=8 && pin<=15){                             //PORTB
		pin-=8;
		if(pinValue){
			PORTB |= (1<<pin);
		}else{
			PORTB &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef PORTC
	else if(pin>=16 && pin<=23){                             //PORTC
		pin-=16;
		if(pinValue){
			PORTC |= (1<<pin);
		}else{
			PORTC &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef PORTD
	else if(pin>=24 && pin<=31){                             //PORTD
		pin-=24;
		if(pinValue){
			PORTD |= (1<<pin);
		}else{
			PORTD &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef PORTE
	else if(pin>=32 && pin<=39){                             //PORTE
		pin-=32;
		if(pinValue){
			PORTE |= (1<<pin);
		}else{
			PORTE &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef PORTF
	else if(pin>=40 && pin<=47){                             //PORTF
		pin-=40;
		if(pinValue){
			PORTF |= (1<<pin);
		}else{
			PORTF &= ~(1<<pin);
		}
	}
	#endif
	
	#ifdef PORTG
	else if(pin>=48 && pin<=55){                             //PORTG
		pin-=48;
		if(pinValue){
			PORTG |= (1<<pin);
		}else{
			PORTG &= ~(1<<pin);
		}
	}
	#endif

}

/**
 * @brief  Toggle the value of a specific pin (invert HIGH/LOW).
 * 
 * This function inverts the current output state of the specified pin.
 * It uses XOR to flip the corresponding bit in the port register.
 *
 * @param   pin       The pin number (0 to 55) that will be toggled.
 * 
 * @return  None
 */
void digitalToggle(pin_t pin){
	#ifdef PORTA
	if(pin<=7){                                                 //PORTA
		PORTA ^= (1<<pin);
	}
	#endif
	
	#ifdef PORTB
	else if(pin>=8 && pin<=15){                             //PORTB
		pin-=8;
		PORTB ^= (1<<pin);
	}
	#endif
	
	#ifdef PORTC
	else if(pin>=16 && pin<=23){                             //PORTC
		pin-=16;
		PORTC ^= (1<<pin);
	}
	#endif
	
	#ifdef PORTD
	else if(pin>=24 && pin<=31){                             //PORTD
		pin-=24;
		PORTD ^= (1<<pin);
	}
	#endif
	
	#ifdef PORTE
	else if(pin>=32 && pin<=39){                             //PORTE
		pin-=32;
		PORTE ^= (1<<pin);
	}
	#endif
	
	#ifdef PORTF
	else if(pin>=40 && pin<=47){                             //PORTF
		pin-=40;
		PORTF ^= (1<<pin);
	}
	#endif
	
	#ifdef PORTG
	else if(pin>=48 && pin<=55){                             //PORTG
		pin-=48;
		PORTG ^= (1<<pin);
	}
	#endif
}

/**
 * @brief  Generate a PWM signal with a specific duty cycle on a given pin.
 * 
 * This function sets up the relevant timer and output compare registers to 
 * generate a PWM waveform on the specified pin with the desired duty cycle. 
 * It supports different ATmega microcontrollers and automatically configures 
 * the proper registers based on the selected pin and microcontroller.
 * 
 * @param   pin         The PWM-capable pin to output the PWM signal on.
 *                      Only specific pins on the supported microcontrollers
 *                      (ATmega32A, ATmega328P) are valid for PWM output.
 * 
 * @param   duty_cycle  The duty cycle for the PWM signal, as a percentage (0-100).
 *                      If set to 0, the PWM output is disabled and the pin is pulled LOW.
 * 
 * @return  None
 */
void digitalPWM(pin_t pin, uint8_t duty_cycle){
	
	if(duty_cycle > 100) duty_cycle = 100;                           // Clamp duty cycle to max 100%
	duty_cycle=duty_cycle*255/100;                                   // Convert duty cycle percentage to 8-bit value (0-255)
	
	#if defined(__AVR_ATmega32A__)
		if(pin==PB_3){                                               // ======= Timer0 - OC0 (PB3) =======
			pinMode(pin,OUTPUT);
			if(duty_cycle==0){
				TCCR0 &= ~((1<<COM01)|(1<<COM00));                   // Disable PWM and write LOW
				digitalWrite(pin,LOW);
				return;
			}
			OCR0=duty_cycle;
			TCCR0|=(1<<WGM01)|(1<<WGM00)|(1<<CS01)|(1<<COM01);
		}
		else if(pin==PD_5){                                          // ======= Timer1 - OC1A (PD5) =======
			pinMode(pin,OUTPUT);
			if(duty_cycle==0){
				TCCR1A &= ~((1<<COM1A1)|(1<<COM1A0));                // Disable PWM and write LOW
				digitalWrite(pin,LOW);
				return;
			}
			OCR1A=duty_cycle;
			TCCR1A|=(1<<COM1A1)|(1<<WGM10);
			TCCR1B|=(1<<WGM12)|(1<<CS11);
		}
		else if(pin==PD_4){                                          // ======= Timer1 - OC1B (PD4) =======
			pinMode(pin,OUTPUT);
			if(duty_cycle==0){
				TCCR1A &= ~((1<<COM1B1)|(1<<COM1B0));                // Disable PWM and write LOW
				digitalWrite(pin,LOW);
				return;
			}
			OCR1B=duty_cycle;
			TCCR1A|=(1<<COM1B1)|(1<<WGM10);
			TCCR1B|=(1<<WGM12)|(1<<CS11);
		}
		else if(pin==PD_7){                                          // ======= Timer2 - OC2 (PD7) =======
			pinMode(pin,OUTPUT);
			if(duty_cycle==0){
				TCCR2 &= ~((1<<COM21)|(1<<COM20));                   // Disable PWM and write LOW
				digitalWrite(pin,LOW);
				return;
			}
			OCR2=duty_cycle;
			TCCR2|=(1<<WGM21)|(1<<WGM20)|(1<<CS21)|(1<<COM21);
		}
	#elif defined(__AVR_ATmega328P__)
		if(pin==PD_6){                                               // ======= Timer0 - OC0A (PD6) =======
			pinMode(pin,OUTPUT);
			if(duty_cycle==0){
				TCCR0A &= ~((1<<COM0A1)|(1<<COM0A0));                // Disable PWM and write LOW
				digitalWrite(pin,LOW);
				return;
			}
			OCR0A=duty_cycle;
			TCCR0A|=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
			TCCR0B|=(1<<CS01);
		}
		else if(pin==PD_5){                                          // ======= Timer0 - OC0B (PD5) =======
			pinMode(pin,OUTPUT);
			if(duty_cycle==0){
				TCCR0A &= ~((1<<COM0B1)|(1<<COM0B0));                // Disable PWM and write LOW
				digitalWrite(pin,LOW);
				return;
			}
			OCR0B=duty_cycle;
			TCCR0A|=(1<<COM0B1)|(1<<WGM01)|(1<<WGM00);
			TCCR0B|=(1<<CS01);
		}
		else if(pin==PB_1){                                          // ======= Timer1 - OC1A (PB1) =======
			pinMode(pin,OUTPUT);
			if(duty_cycle==0){
				TCCR1A &= ~((1<<COM1A1)|(1<<COM1A0));                // Disable PWM and write LOW
				digitalWrite(pin,LOW);
				return;
			}
			OCR1A=duty_cycle;
			TCCR1A|=(1<<COM1A1)|(1<<WGM10);
			TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);
		}
		else if(pin==PB_2){                                          // ======= Timer1 - OC1B (PB2) =======
			pinMode(pin,OUTPUT);
			if(duty_cycle==0){
				TCCR1A &= ~((1<<COM1B1)|(1<<COM1B0));                // Disable PWM and write LOW
				digitalWrite(pin,LOW);
				return;
			}
			OCR1B=duty_cycle;
			TCCR1A|=(1<<COM1B1)|(1<<WGM10);
			TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);
		}
		else if(pin==PB_3){                                          // ======= Timer2 - OC2A (PB3) =======
			pinMode(pin,OUTPUT);
			if(duty_cycle==0){
				TCCR2A &= ~((1<<COM2A1)|(1<<COM2A0));                // Disable PWM and write LOW
				digitalWrite(pin,LOW);
				return;
			}
			OCR2A=duty_cycle;
			TCCR2A|=(1<<COM2A1)|(1<<WGM21)|(1<<WGM20);
			TCCR2B|=(1<<CS21);
		}
		else if(pin==PD_3){                                          // ======= Timer1 - OC1B (PD3) =======
			pinMode(pin,OUTPUT);
			if(duty_cycle==0){
				TCCR2A &= ~((1<<COM2B1)|(1<<COM2B0));                // Disable PWM and write LOW
				digitalWrite(pin,LOW);
				return;
			}
			OCR2B=duty_cycle;
			TCCR2A|=(1<<COM2B1)|(1<<WGM21)|(1<<WGM20);
			TCCR2B|=(1<<CS21);
		}
	#else
	#error "Unsupported microcontroller"
	#endif
}
/**
 * @brief  Read the value of a specific pin.
 * 
 * This function reads the current input state of the specified pin. It checks 
 * the corresponding port register to determine whether the pin is HIGH or LOW.
 *
 * @param   pin       The pin number (0 to 55) that will be read.
 * 
 * @return  HIGH if the pin is high, LOW if the pin is low.
 *          If the pin number is invalid, it returns -1.
 */
int8_t digitalRead(pin_t pin){
	#ifdef PINA
	if(pin<=7){                                                  //PORTA
		return ((PINA & (1<<pin)) ? HIGH : LOW);
	}
	#endif
	
	#ifdef PINB
	else if(pin>=8 && pin<=15){                              //PORTB
		pin-=8;
		return ((PINB & (1<<pin)) ? HIGH : LOW);
	}
	#endif
	
	#ifdef PINC
	else if(pin>=16 && pin<=23){                              //PORTC
		pin-=16;
		return ((PINC & (1<<pin)) ? HIGH : LOW);
	}
	#endif
	
	#ifdef PIND
	else if(pin>=24 && pin<=31){                              //PORTD
		pin-=24;
		return ((PIND & (1<<pin)) ? HIGH : LOW);
	}
	#endif
	
	#ifdef PINE
	else if(pin>=32 && pin<=39){                              //PORTE
		pin-=32;
		return ((PINE & (1<<pin)) ? HIGH : LOW);
	}
	#endif
	
	#ifdef PINF
	else if(pin>=40 && pin<=47){                              //PORTF
		pin-=40;
		return ((PINF & (1<<pin)) ? HIGH : LOW);
	}
	#endif
	
	#ifdef PING
	else if(pin>=48 && pin<=55){                              //PORTG
		pin-=48;
		return ((PING & (1<<pin)) ? HIGH : LOW);
	}
	#endif
	
	return -1;
}
