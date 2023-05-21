/*
4. Write a C language program that generates a square wave on P0.0 with ON time 3ms
and OFF time 10ms
*/

#include<reg51.h>

#define MAX_ITER (250)

sbit p0d0Bit = P0^0;


// Generates X ms delay
void delay_ms(int count){
	
	int j = 0;
	
	// Repeat 1 ms delay loop count times
	while(j < count){
		int i = 0;
		
		// This loop generates approx 1 ms delay
		while(i < MAX_ITER){
			i++;
		}
		j++;
	}
	return;
}

void main(void){
	
	for(;;){
		p0d0Bit = 1;
		delay_ms(3);
		p0d0Bit = 0;
		delay_ms(10);
	}
	
	return;
}