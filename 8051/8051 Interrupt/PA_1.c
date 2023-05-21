#include<reg51.h>

sbit SW = P1^7;
sbit P1_0 = P1^0;

sbit WAVE = P1^5;

void timer0(void) interrupt 1{
    WAVE = ~WAVE;
}

void init_timer(void){
    TMOD = 0x02;
    TH0 = -100;
    IE = 0x82;
    TR0 = 1;
    return;
}

void main(void){
    init_timer();
    while (1)
    {
        P1_0 = SW;
    }
    
    return;
}