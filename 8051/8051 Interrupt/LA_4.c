#include<reg51.h>

sbit WAVE = P2^1;

void timer0(void) interrupt 1{
	WAVE = ~WAVE;
	return;
}

void main(void){
	
	TMOD = 0x62;	// Enabling Timer 1 as counter and Timer 0 in Auto-Reload mode
	TH0 = -46;		// For 50us delay
	TL1 = 0;			//Timer 1 counter mode
	P2 = 0;
	P3 = 0;
	IE = 0x82;
	
	// Setting Timer 0 and 1 ON
	TR1 = 1;
	TR0 = 1;
	
	// Till Counter overflows
	while(!TF1){
		P0 = TL1;				// Send total count value to P0
	}
	
	return;
}
