#include<REG51.H>

// Define a single bit for the switch SW using bit-addressing syntax
sbit SW = P2^0;

// Function to initialize the serial communication settings
void init_serial(void){
	// Set timer 1 in Mode 2 (8-bit auto-reload)
	// and enable the receiver and transmitter
	TMOD = 0x50;
	// Set the baud rate for serial communication
	TH1 = -3;
	// Start Timer 1
	TR1 = 1;

	return;
}

// Function to send a string of characters through serial communication
void send(char str[]){
	// Declare an unsigned character variable i
	unsigned char i;

	// Loop through the string until a null character is encountered
	for (i = 0; str[i]!='\0'; i++)
	{
		// Send each character of the string one-by-one
		SBUF = str[i];
		// Wait for the transmit interrupt flag to be set
		while(!TI);
		// Clear the transmit interrupt flag to indicate completion of transmission
		TI = 0;
	}
	
	return;
}


void main(void){
	// Declare character arrays for first and last name
	char fname[10] = "Manav ";
	char lname[10] = "Chokshi ";
	
	// Initialize port 2 to 0
	P2 = 0x00;
	// Initialize serial communication settings
	init_serial();

	// Infinite loop
	while(1){
		// While the switch is on
		while (SW)
		{
			// Send the first name string
			send(fname);
		}
		// While the switch is off
		while (!SW)
		{
			// Send the last name string
			send(lname);
		}
	}

	// The return statement is not strictly necessary, as the main function does not return a value
	return;
}
