#include <LPC214x.h>
#include "PLL.h"

void initPLL(void){
	
	PLL0CON = 0x01;
	PLL0CFG = 0x24;  // MSEL -> 4, PSEL -> 1
	PLL0FEED = 0xaa;
	PLL0FEED = 0x55;
	
	while(!(PLL0STAT & (1 << LOCK)));
	
	PLL0CON = 0x03;
	PLL0FEED = 0xaa;
	PLL0FEED = 0x55;
	VPBDIV = 0x01;
	
	return;
}
