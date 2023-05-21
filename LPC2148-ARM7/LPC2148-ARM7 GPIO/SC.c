#include <LPC214x.h>

/* Since all LEDs are connected to common Anode.
	Hence, at HIGH, LED remains OFF and, at LOW, LED turns ON.
	
	Therefore to turn on the LEDs, we must clear the bits.
	And to turn off the LEDs, we must set the bits.
*/

#define ledON IO0CLR
#define ledOFF IO0SET
#define LED (0x000000FF)

int main(void){
	
	unsigned long int count = 0;
	PINSEL0  = 0x00000000;
	IO0DIR = 0xFFFFFFFF;
	ledOFF = LED;
	
	while(1){
		for(count = 0; count < 60000; count++); 
		ledON = LED;
		for(count = 0; count < 60000; count++); 
		ledOFF = LED;
	}
	return 0;
}
