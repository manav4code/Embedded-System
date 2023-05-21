/*
Assume that we have 4 bytes of data 25H, 62H, 3FH, and 52 H. Write a C program to
calculate the checksum.
*/

#include<reg51.h>

sbit checkSum = P0^0;

void main(void){
	int num[] = {0x25,0x62,0x3f,0x52};
	unsigned char i;
	int sum = 0;
	P0 = 0x00;
	
	for(i = 0; i < 4; i++){
		sum += num[i];
	}
	
	sum = ~sum + 1;

	P1 = sum;
	P2 = sum >> 8;
	
/*
	for(i = 0; i < 16; i++){
		if(sum &(1 << i)){
			checkSum = ~checkSum;
		}
	}
*/
	return;
}