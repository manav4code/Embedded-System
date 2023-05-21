#include<reg51.h>

#define xtal (11059200UL)
#define freq (500UL)
#define reload_val (65536 - (xtal/(12UL*2UL*freq)))


void timer(void){
	TH0 = (unsigned char)(reload_val >> 8);
	TL1 = (unsigned char)(reload_val);
	TR0 = 1;
	
	while(!TF0);
	TF0 = 0;
	TR0 = 0;
	return;
}

void main(void){
	TMOD = 0x01;
	P0 = 0xAA;
	
	while(1){
		P0 = ~P0;
		timer();
	}
	return;
}