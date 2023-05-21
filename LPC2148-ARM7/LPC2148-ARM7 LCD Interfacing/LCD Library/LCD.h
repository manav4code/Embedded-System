#ifndef LCD_H
#define LCD_H

#include <LPC214x.h>


#define LcdDataBusPort IO0PIN
#define LcdControlBusPort IO0PIN
#define LcdDataBusDirReg IO0DIR

// PINS
#define LCD_RS 13
#define LCD_RW 4
#define LCD_EN 12
#define LCD_D4 8
#define LCD_D5 9
#define LCD_D6 10
#define LCD_D7 11

// MASK

#define LcdCtrlBusMask (1<<LCD_RS)|(1<<LCD_RW)
#define LcdDataBusMask (1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)


// Functions
void sendNibble(char nibble);
void Lcd_CmdWrite(char cmd);
void Lcd_DataWrite(char data);
void initLcd(void);
void setCursor(unsigned char lineNo);
void Lcd_WriteLine(char str[]);

#endif