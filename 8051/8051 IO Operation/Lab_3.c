/*
Q3. Write an 8051 C program to toggle bit D0 of the port P1 (P1.0) 50,000 times
*/

#include<reg51.h>

#define MAX_COUNT (50000)

sbit p1_bit = P1^0; 		// D0 of port 1

void main(void){
	int i = 0;

	P1 = 0x00;   					// Clearing all bits
	
	for(i = 0; i < MAX_COUNT; ++i){
		// Toggling
		p1_bit = ~p1_bit;
	}
	return;
}