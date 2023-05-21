
#include <LPC214x.h>
#include "LCD.h"

int main(){
	initLcd();
	Lcd_WriteLine("Hello..");
	while(1){
		// Shift display right
		shiftDisplay(1);
	}
	return 0;
}
