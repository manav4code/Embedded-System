/*
In above Program 4, if by chance 62H becomes 22H. Then show that how checksum
detect the error. The error may be detected by sending ‘1’ to P1.0 and no error ‘0’ can be
sent to P1.1
*/

#include<reg51.h>

sbit error = P1^0;
sbit good = P1^1;

void main(void){
	unsigned char checkSum1,sum,send,rec;
	
	send = 0x62;
	rec = 0x22;
	
	P1 = 0x00;
	
	// Sending
	checkSum1 = ~send;
	
	// Receiving
	sum = ~(rec + checkSum1);
	if(sum == 0){
		good = 0;
	}
	else error = 1;
	
	return;
}