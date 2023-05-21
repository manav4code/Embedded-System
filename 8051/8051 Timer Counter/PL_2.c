#include<reg51.h>

void main(void){
	P3 = 0x00;
	TMOD = 0x05;
	TL0 = 0x00;
	TH0 = 0x00;
	
	while(1){
		TR0 = 1;
		P1 = TL0;
		P2 = TH0;
		while(TF0 == 0){
			P1 = TL0;
			P2 = TH0;
		}
		TF0 = 0;
	}
	return;
}