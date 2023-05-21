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
        // Shifts Left
        shiftDisplay(0);
        delay(100);
    }
    
    return 0;
}