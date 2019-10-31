/*
 * Lab8_ex3.c
 *
 * Created: 10/29/2019 12:39:29 PM
 * Author : Matthew L
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; 
	DDRB = 0xFF; PORTB = 0x00; 
	DDRD = 0xFF; PORTD = 0x00;
	
	ADC_init();
	unsigned short max = 816;
	unsigned char tempB = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		unsigned short x = ADC; 
		
		if(x > max){
			max = x;
		}
		if (x >= max/2){
			tempB = 0x00;
		}
		else{
			tempB = 0x01;
		}

		PORTB = tempB;
    }
}

