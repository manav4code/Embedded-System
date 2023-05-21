
/*
Q1. Write an 8051 C program to toggle all the bits of P1 continuously
*/

#include<reg51.h>


void main(void){
	
	P1 = 0xFF;

	// Toggling content of P1 continously
	while(1){
			P1 = ~P1;
	}

	return;
}