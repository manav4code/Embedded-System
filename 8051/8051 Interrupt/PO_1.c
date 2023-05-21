#include<reg51.h>

sbit WAVE_5 = P2^1;
sbit WAVE_25 = P2^2;

void timer0(void) interrupt 1{
    WAVE_5 = ~WAVE_5;
}

void timer1(void) interrupt 3{
    WAVE_25 = ~WAVE_25;
}

void initTimer(void){
    IE = 0x8A;   // i.e 10001010

    TMOD = 0x22;
    
    TH0 = -100;
    TH1 = -20;

    TR0 = 1;
    TR1 = 1;    
}


void main(void){

    P2 = 0x00;
    initTimer();
    while(1){
        // Do anything
    }
    return;
}


