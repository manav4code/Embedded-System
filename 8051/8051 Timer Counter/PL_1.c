#include<reg51.h>

void main(void){
	P3 = 0x00;

	// Setting Timer 1 as counter
	TMOD = 0x50;

	// Loading 20000 initial value
	TL1 = (20000);
	TH1 = ((20000)>>8);
	
	while(1){
		TR1 = 1;
		P1 = TL1;
		P2 = TH1;
		
		// Keep counting till it overflows
		while(TF1 == 0){
			P1 = TL1;
			P2 = TH1;
		}
		TF1 = 0;
	}
	return;
}