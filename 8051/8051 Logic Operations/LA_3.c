/*
Write an 8051 C program to read the bits of P1.0 and P1.1 and issue an ASCII character
to P0 according to the following table 
*/

#include<reg51.h>

void main(void){
	char ascii[] = {'0','1','2','3'};
	P1 = 0x00;
	while(1){
		if(!(P1 & (1<<1))&& !(P1 & (1<<0)))
			P0 = ascii[0];
		else if(!(P1 & (1<<1))&&(P1 & (1<<0)))
			P0 = ascii[1];
		else if((P1 & (1<<1))&& !(P1 & (1<<0)))
			P0 = ascii[2];
		else
			P0 = ascii[3];
	}
	
	return;
}