/*
 * GAGHL_AVR_GPIO.c
 *
 * Created: 4/29/2025 11:58:00 PM
 *  Author: GAGHL
 */ 

#include "GAGHL_AVR_GPIO.h"

void gpioDir(uint8_t Pin_num,uint8_t Pin_dir, uint8_t io_stat){
	#ifdef DDRA
	if(Pin_num<=7){                                                  //PORTA
		if(Pin_dir){
			DDRA |= (1<<Pin_num);
		}else{
			DDRA &= ~(1<<Pin_num);
			if(io_stat){
				PORTA |= (1<<Pin_num);
			}else{
				PORTA &= ~(1<<Pin_num);
			}
		}
		
	}
	#endif
	
	#ifdef DDRB
	else if(Pin_num>=8 && Pin_num<=15){                              //PORTB
		Pin_num-=8;
		if(Pin_dir){
			DDRB |= (1<<Pin_num);
		}else{
			DDRB &= ~(1<<Pin_num);
			if(io_stat){
				PORTB |= (1<<Pin_num);
			}else{
				PORTB &= ~(1<<Pin_num);
			}
		}
	}
	#endif
	
	#ifdef DDRC
	else if(Pin_num>=16 && Pin_num<=23){                              //PORTC
		Pin_num-=16;
		if(Pin_dir){
			DDRC |= (1<<Pin_num);
		}else{
			DDRC &= ~(1<<Pin_num);
			if(io_stat){
				PORTC |= (1<<Pin_num);
			}else{
				PORTC &= ~(1<<Pin_num);
			}
		}
	}
	#endif
	
	#ifdef DDRD
	else if(Pin_num>=24 && Pin_num<=31){                              //PORTD
		Pin_num-=24;
		if(Pin_dir){
			DDRD |= (1<<Pin_num);
		}else{
			DDRD &= ~(1<<Pin_num);
			if(io_stat){
				PORTD |= (1<<Pin_num);
			}else{
				PORTD &= ~(1<<Pin_num);
			}
		}
	}
	#endif
	
	#ifdef DDRE
	else if(Pin_num>=32 && Pin_num<=39){                              //PORTE
		Pin_num-=32;
		if(Pin_dir){
			DDRE |= (1<<Pin_num);
		}else{
			DDRE &= ~(1<<Pin_num);
			if(io_stat){
				PORTE |= (1<<Pin_num);
			}else{
				PORTE &= ~(1<<Pin_num);
			}
		}
	}
	#endif
	
	#ifdef DDRF
	else if(Pin_num>=40 && Pin_num<=47){                              //PORTF
		Pin_num-=40;
		if(Pin_dir){
			DDRF |= (1<<Pin_num);
		}else{
			DDRF &= ~(1<<Pin_num);
			if(io_stat){
				PORTF |= (1<<Pin_num);
			}else{
				PORTF &= ~(1<<Pin_num);
			}
		}
	}
	#endif
	
	#ifdef DDRG
	else if(Pin_num>=48 && Pin_num<=55){                              //PORTG
		Pin_num-=48;
		if(Pin_dir){
			DDRG |= (1<<Pin_num);
		}else{
			DDRG &= ~(1<<Pin_num);
			if(io_stat){
				PORTG |= (1<<Pin_num);
			}else{
				PORTG &= ~(1<<Pin_num);
			}
		}
	}
	#endif
}
void digitalWrite(uint8_t Pin_num, uint8_t Pin_val){
	#ifdef PORTA
	if(Pin_num<=7){                                                 //PORTA
		Pin_num-=0;
		if(Pin_val){
			PORTA |= (1<<Pin_num);
		}else{
			PORTA &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTB
	else if(Pin_num>=8 && Pin_num<=15){                             //PORTB
		Pin_num-=8;
		if(Pin_val){
			PORTB |= (1<<Pin_num);
		}else{
			PORTB &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTC
	else if(Pin_num>=16 && Pin_num<=23){                             //PORTC
		Pin_num-=16;
		if(Pin_val){
			PORTC |= (1<<Pin_num);
		}else{
			PORTC &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTD
	else if(Pin_num>=24 && Pin_num<=31){                             //PORTD
		Pin_num-=24;
		if(Pin_val){
			PORTD |= (1<<Pin_num);
		}else{
			PORTD &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTE
	else if(Pin_num>=32 && Pin_num<=39){                             //PORTE
		Pin_num-=32;
		if(Pin_val){
			PORTE |= (1<<Pin_num);
		}else{
			PORTE &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTF
	else if(Pin_num>=40 && Pin_num<=47){                             //PORTF
		Pin_num-=40;
		if(Pin_val){
			PORTF |= (1<<Pin_num);
		}else{
			PORTF &= ~(1<<Pin_num);
		}
	}
	#endif
	
	#ifdef PORTG
	else if(Pin_num>=48 && Pin_num<=55){                             //PORTG
		Pin_num-=48;
		if(Pin_val){
			PORTG |= (1<<Pin_num);
		}else{
			PORTG &= ~(1<<Pin_num);
		}
	}
	#endif

}

int8_t digitalRead(uint8_t Pin_num){
	#ifdef PINA
	if(Pin_num<=7){                                                  //PORTA
		Pin_num-=0;
		return (PINA & (1<<Pin_num));
	}
	#endif
	
	#ifdef PINB
	else if(Pin_num>=8 && Pin_num<=15){                              //PORTB
		Pin_num-=8;
		return (PINB & (1<<Pin_num));
	}
	#endif
	
	#ifdef PINC
	else if(Pin_num>=16 && Pin_num<=23){                              //PORTC
		Pin_num-=16;
		return (PINC & (1<<Pin_num));
	}
	#endif
	
	#ifdef PIND
	else if(Pin_num>=24 && Pin_num<=31){                              //PORTD
		Pin_num-=24;
		return (PIND & (1<<Pin_num));
	}
	#endif
	
	#ifdef PINE
	else if(Pin_num>=32 && Pin_num<=39){                              //PORTE
		Pin_num-=32;
		return (PINE & (1<<Pin_num));
	}
	#endif
	
	#ifdef PINF
	else if(Pin_num>=40 && Pin_num<=47){                              //PORTF
		Pin_num-=40;
		return (PINF & (1<<Pin_num));
	}
	#endif
	
	#ifdef PING
	else if(Pin_num>=48 && Pin_num<=55){                              //PORTG
		Pin_num-=48;
		return (PING & (1<<Pin_num));
	}
	#endif
}
