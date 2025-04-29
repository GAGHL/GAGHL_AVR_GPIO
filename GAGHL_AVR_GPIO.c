/*
 * GAGHL_AVR_GPIO.c
 *
 * Created: 4/29/2025 11:58:00 PM
 *  Author: GAGHL
 */ 
#include "GAGHL_AVR_GPIO.h"

void digitalWrite(uint8_t Pin_num, uint8_t Pin_val){
	#ifdef PORTA
	if(Pin_num<=7){                                                  //PORTA
		Pin_num-=0;
		if(Pin_val){
			PORTA |= (1<<Pin_num);
			}else{
			PORTA &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTB
	else if(Pin_num>=8 && Pin_num<=15){                              //PORTB
		Pin_num-=8;
		if(Pin_val){
			PORTB |= (1<<Pin_num);
			}else{
			PORTB &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTC
	else if(Pin_num>=16 && Pin_num<=23){                              //PORTC
		Pin_num-=16;
		if(Pin_val){
			PORTC |= (1<<Pin_num);
			}else{
			PORTC &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTD
	else if(Pin_num>=24 && Pin_num<=31){                              //PORTD
		Pin_num-=24;
		if(Pin_val){
			PORTD |= (1<<Pin_num);
			}else{
			PORTD &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTE
	else if(Pin_num>=32 && Pin_num<=39){                              //PORTE
		Pin_num-=32;
		if(Pin_val){
			PORTE |= (1<<Pin_num);
			}else{
			PORTE &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTF
	else if(Pin_num>=40 && Pin_num<=47){                              //PORTF
		Pin_num-=40;
		if(Pin_val){
			PORTF |= (1<<Pin_num);
			}else{
			PORTF &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTG
	else if(Pin_num>=48 && Pin_num<=55){                              //PORTG
		Pin_num-=48;
		if(Pin_val){
			PORTG |= (1<<Pin_num);
			}else{
			PORTG &= ~(1<<Pin_num);
		}
	}
	#endif
	
}
