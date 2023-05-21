/*
Write an 8051 C program to toggle all the bits of P0 and P2 continuously with some
delay. Use the inverting operator.
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

void main(void){
	while(1){
		P0 = ~P0;
		P2 = ~P2;
		delay_ms(10);
	}
	return;
}