#include "UART.h"
#include <LPC214x.h>

void initUART0(void){
	unsigned char temp;
	U0LCR = 0x83;
	temp = (fpclk/16)/baud_9600;
	U0DLM = temp/256;
	U0DLL = temp%256;
	U0FCR = 0x01;
	U0LCR = 0x03;
}

void UART0_sendByte(unsigned char data){
	U0THR = data;
	while((U0LSR & 0x40) == 0);
}

int UART0_getByte(void){
	while((U0LSR & 0x01) == 0);
	return U0RBR;
}
