#include<reg51.h>

#define XTAL (11059200)
#define FREQ1 (500UL)
#define FREQ2 (750UL)
#define reload_val1 (65536UL - (XTAL/(12UL*FREQ1)))
#define reload_val2 (65536UL - (XTAL/(12UL*FREQ2)))


sbit SW = P1^2;
sbit OUT = P1^7;

// For 500Hz
void timer_1(void){

    TH0 = (unsigned char)(reload_val1 >> 8);
    TL0 = (unsigned char)(reload_val1);
    TR0 = 1;

    while(!TF0);

    TF0 = 0;
    TR0 = 0;

    return;
}

// for 750Hz
void timer_2(void){

    TH0 = (unsigned char)(reload_val2 >> 8);
    TL0 = (unsigned char)(reload_val2);
    TR0 = 1;

    while(!TF0);

    TF0 = 0;
    TR0 = 0;

    return;
}

void main(void){
		TMOD = 0x01;
    OUT = 0;
		P1 = 0x00;
	
    while(1){
        while(!SW){
            OUT = ~OUT;
            timer_1();
        }
        while(SW){
            OUT = ~OUT;
            timer_2();
        }
    }
    return;
}