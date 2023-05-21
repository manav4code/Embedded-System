#include<reg51.h>

sbit LED = P2^1;
unsigned char sig = 0;

void timer0(void) interrupt 1{
	if(sig < 6){
		LED = ~LED;
		sig++;
		TR0= 1;
	}
	else TR0 = 0;
	
	TF0 = 0;
}

void serail(void) interrupt 4{
	sig = 0;
	TR0 = 1;
	RI = 0;
}

void initSerial(void){
	TMOD = 0x20;
	TH1 = -3;
	SCON = 0x50;
	TR1 = 1;
	IE |= 0x10;
}

void initTimer(void){
	TMOD = 0x01;
	TH0 = 0x00;
	TL0 = 0x01;
	IE |= 0x02;
}

void main(void){
	
	initTimer();
	initSerial();
	
	IE |= 0x90;
	LED = 0;

	while(1);
}
