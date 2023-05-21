 /*

Q2. Write an 8051 C program to get a byte of data from P1, wait ½ second, and then send it
to P2

*/

#include<reg51.h>

#define MAX_ITER 16000

void Delay_100ms(int count){
	
	int j = 0;
	
	while(j < count){
		int i = 0;
		while(i < MAX_ITER){
			++i;
		}
		++j;
	}
	return;
}

void main(void){
	
		P1 = 0xFF;
	
		while(1){
			int temp = P1;
			Delay_100ms(10);
			P2 = temp;
		}
		
	return;
}