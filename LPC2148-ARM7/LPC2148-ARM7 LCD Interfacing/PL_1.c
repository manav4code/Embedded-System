#include <LPC214x.h>
#include "LCD.h"

void delay(int cnt){
    int i,j;
    for(i=0;i<cnt;i++){
        for(j=0;j<10;j++);
    }
    return;
}

int main(){
    initLcd();
    Lcd_WriteLine("Nirma");
    setCursor(1);
    Lcd_WriteLine("University");

    while(1){
        Lcd_CmdWrite(0x0C); // Display on, cursor off
        delay(100);
        // Shifts Left
        shiftDisplay(0);
        delay(100);
        Lcd_CmdWrite(0x08); // Display off, Cursor Off
        delay(100);
    }
    
    return 0;
}