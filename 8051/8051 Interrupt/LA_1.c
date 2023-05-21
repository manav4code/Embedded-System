#include<reg51.h>

sbit SW = P1^7;
sbit WAVE = P2^5;
sbit OUT = P1^0;

void timer0(void) interrupt 1{
    WAVE = ~WAVE;      // Toggle bit
}

void serial(void) interrupt 4{
	TI = 0;         // Reset Tx Flag
    SBUF = 'A';     // Resend 'A'
}

void initTimer(void){
		IE |= 0x02;		// Enable Timer 0 IRQ
    TMOD |= 0x02;	// Timer 0 - Auto Reload Mode
    TH0 = -100;
    TR0 = 1;			// Start Timer 0
}

void initSerial(void){
		IE |= 0x10;			// Enable Serial IRQ
    SCON = 0x50;		// Serial Mode 2 and Receive Enable
    TMOD |= 0x20;		// Timer 1 - Auto reload mode
    TH1 = -3;				// 9600 Baud Rate
    TR1 = 1;
}		

void main(void){

    P1 = 0x00;
    initTimer();	// Initialize Timer
    initSerial();	// Initialize Serial Com
	
		IE |= 0x80;		// Enable all interrupts
		
		// Start Serial
		SBUF = 'A';
		WAVE = 0;
		
    while (1)
    {
        OUT = SW;
    }
    
    return;
}