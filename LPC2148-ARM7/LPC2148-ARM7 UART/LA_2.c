#include <LPC214x.h>
#include "UART.h"
#include "LCD.h"

int main(){
	unsigned char data;
	PINSEL0 = 0x00000005;
	
	initUART0();
	initLcd();
	
	setCursor(0);
	
	while(1){
		data = UART0_getByte();
		Lcd_DataWrite(data);
	}
}
