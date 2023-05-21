#include<reg51.h>

void main(void){

	// Configure Timer 1 in mode 2
	TMOD = 0x20;
	// Set Timer 1's reload value to -6 (4800 baud at 11.0592 MHz)
	TH1 = -6;
	// Start Timer 1
	TR1 = 1;
	// Configure the serial port for mode 1, 8-bit data, and enable reception
	SCON = 0x50;

	// Loop forever
	while (1)
	{
		// Wait for a character to be received
		while (!RI);
		// Move the received character into P1, which is an 8-bit output port
		P1 = SBUF;
		// Clear the receive interrupt flag
		RI = 0;
	}

	// This line is not strictly necessary, as the main function does not return a value
	return;
}
