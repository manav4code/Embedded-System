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
	unsigned char i = 0;
	unsigned long int count = 0;
	PINSEL0  = 0x00000000;
	IO0DIR = 0xFFFFFFFF;
	ledOFF = LED;
	
	while(1){
		// Left -> Right
		for(i = 0; i < 8; i++){
			ledON = (0x00000080 >> i);
			// Dividing by i to vary the amount of delay
			for(count = 0; count < (600000/i); count++);
			ledOFF = (0x00000080 >> i);
		}
		
		// Right -> Left
		for(i = 0; i < 8; i++){
			ledON = (0x00000001 << i);
			for(count = 0; count < (600000/i); count++);
			ledOFF = (0x00000001 << i);
		}
		
	}
	return 0;
}
