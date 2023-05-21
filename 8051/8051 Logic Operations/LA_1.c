/*
A door sensor is connected to the P1.1 pin, and a buzzer is connected to the P1.7. Write
an 8051 C program to monitor the door sensor, and when it opens, sound the buzzer
*/

#include<reg51.h>
#define MAX_ITER (4000)

void delay_ms(int count){
	int j = 0;
	while(j < count){
		int i =0;
		while(i < MAX_ITER)
			i++;
		j++;
	}
	return;
}


sbit sensor = P1^1;
sbit buzzer = P1^7;


void main(void){
	P1 = 0x00;
	sensor = 0;
	buzzer = 0;
	
	while(1){		
		while(sensor){
			buzzer = ~buzzer;
			delay_ms(10);
		}
		buzzer = 0;
	}
	return;
}

