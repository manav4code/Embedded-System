#include<reg51.h>

#define receiveData P0
#define getData P1

sbit WAVE = P3^7;
sbit P2_0 = P2^0;

void timer0(void) interrupt 1{
    WAVE = ~WAVE;
}

void serial(void) interrupt 4{
    receiveData = SBUF;
    RI = 0;
}

void delay2s(void){
    unsigned int i, j;
    for(i = 0; i < 5000; i++){ // Adjust the loop count to get the desired delay
        for(j = 0; j < 1000; j++){ // Adjust the inner loop count to get the desired delay
            // Do nothing
        }
    }
}


void initTimer(void){
    IE |= 0x02;
    TMOD |= 0x02;
    TH0 = -100;
    TR0 = 1;
}

void initSerial(void){
    IE |= 0x10;
    SCON = 0x50;
    TMOD |= 0x20;
    TH1 = -3;
    TR1 = 1;
}

void main(void){

    unsigned char i = 0;
		unsigned char temp,count;
    P0 = 0x00;
    IE |= 0x80;

    initTimer();
    initSerial();
	
		P3 = 0x00;

    for(i = 1; i <= 255; i++){
        getData = i;
				temp = getData;
				count = 7;
        do{
            P2_0 = temp & (1<<count);
						P2 = P2 << 1;
						count--;
        }while(count > 0);
				delay2s();
    }
    return;
}
