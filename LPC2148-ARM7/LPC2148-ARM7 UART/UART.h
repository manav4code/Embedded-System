#ifndef UART_H

#define UART_H

#define fosc (12000000)
#define fcclk (fosc*5)
#define fcco (fcclk*4)
#define fpclk (fcclk/4)*1
#define baud_9600 (9600)

void initUART0(void);
void UART0_sendByte(unsigned char data);
int UART0_getByte(void);

#endif
