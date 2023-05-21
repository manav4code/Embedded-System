#include<REG51.H>

sbit SW = P2^0; // Declare switch as a bit

void init_serial(void) {
    TMOD = 0x20; // Set timer 1 to mode 2, auto-reload
    PCON |= 0x80; // Set SMOD bit for baud rate doubling
    TH1 = 0xFF; // Set baud rate to 9600 bps
    TR1 = 1; // Start timer 1
	SCON = 0x50;
    return;
}

void send(char str[]) {
    unsigned char i;

    for (i = 0; str[i] != '\0'; i++) { // Loop through the string until null terminator is found
        SBUF = str[i]; // Load character into serial buffer
        while(!TI); // Wait for transmit interrupt flag to be set
        TI = 0; // Clear transmit interrupt flag
    }
    return;
}

void main(void) {
    char str[] = "The earth is but one country and mankind its citizens";

    P2 = 0x00; // Initialize P2 to 0
    init_serial(); // Initialize serial communication

    while(1) {
        send(str); // Send the string
    }

    return;
}
