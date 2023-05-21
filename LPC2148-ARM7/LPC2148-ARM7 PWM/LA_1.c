#include <LPC214x.h>
#include "PLL.h"

#define N (8)

static void initPWM(void){
	PWMPCR = 0x00;
	PWMPR = 60000-1;
	
	PWMMR0 = 10;
	
	PWMMCR = (1<<1);
	PWMLER = (1<<3)|(1<<0);
	PWMPCR = (1 << 11);
	PWMTCR = (1<<1);
	PWMTCR = (1<<0)|(1<<3);
}

int main(){
	unsigned char i = 0;
	PINSEL0 = 0x00000008;
	
	// Initialize PWM
	initPLL();
	
	// Initialize PWM5
	initPWM();
	
	
	while(1){
		PWMMR3 = i%N;
		PWMLER = (1 << 3)|(1 << 0);
		i++;
	}
	
	return 0;
}
