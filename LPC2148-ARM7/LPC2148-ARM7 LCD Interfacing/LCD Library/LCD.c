#include "LCD.h"

static void delay(int cnt){
	int i,j;
	
	for(i=0;i<cnt;i++){
		for(j=0;j<10;j++);
	}
	return;
}


void Lcd_Enable(){
	LcdControlBusPort |= (1<<LCD_EN);
	delay(1000);
	LcdControlBusPort &= ~(1<<LCD_EN);
	delay(1000);
	return;
}

void sendNibble(char nibble){
	LcdDataBusPort = ~(LcdDataBusMask);
	
	LcdDataBusPort |= (((nibble) >> 0)&1) << LCD_D4;
	LcdDataBusPort |= (((nibble) >> 1)&1) << LCD_D5;
	LcdDataBusPort |= (((nibble) >> 2)&1) << LCD_D6;
	LcdDataBusPort |= (((nibble) >> 3)&1) << LCD_D7;
	
	return;
}

void Lcd_CmdWrite(char cmd){
	// Sending upper nibble
	sendNibble((cmd >> 4) & 0x0F);
	LcdControlBusPort &= ~(LcdCtrlBusMask);
	Lcd_Enable();
	
	// Sending lower nibble
	sendNibble(cmd & 0x0F);
	LcdControlBusPort &= ~(LcdCtrlBusMask);
	Lcd_Enable();
	return;
}

void Lcd_DataWrite(char data){
	// Sending upper nibble
	sendNibble((data >> 4) & 0x0F);
	LcdControlBusPort &= ~(LcdCtrlBusMask);
	Lcd_Enable();
	
	// Sending lower nibble
	sendNibble(data & 0x0F);
	LcdControlBusPort &= ~(LcdCtrlBusMask);
	Lcd_Enable();	
	return;
}

void initLcd(void){
	unsigned char i;
	char initCmd[] = {0x02,0x28,0x0E,0x01,0x80};
	
	LcdDataBusDirReg |= LcdDataBusMask;
	LcdDataBusDirReg |= (LcdCtrlBusMask | (1 << LCD_EN));
	
	for(i = 0;i < 5;i++){
		Lcd_CmdWrite(initCmd[i]);
	}
	return;
}

void Lcd_WriteLine(char str[]){
	unsigned char i = 0;
	for(i = 0; str[i] != '\0'; i++){
		Lcd_DataWrite(str[i]);
	}
}

void setCursor(unsigned char lineNo){
	if(lineNo){
		Lcd_CmdWrite(0xC0);
	}
	else Lcd_CmdWrite(0x80);
}