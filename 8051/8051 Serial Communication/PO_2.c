#include <REG51.H>

sbit SW = P2^0; // Define a switch on Port 2 bit 0

// Function to initialize serial communication
void init_serial(void) {
    TMOD = 0x20;   // Set timer mode for baud rate generation
    PCON |= 0x80;  // Set SMOD bit for baud rate doubling
    TH1 = 0xFF;    // Load TH1 with a value for desired baud rate
    TR1 = 1;       // Start Timer 1
    SCON = 0x50;   // Set serial communication mode and enable receiver
}

// Function to send a string over serial communication
void send(char str[]) {
    unsigned char i;

    for (i = 0; str[i] != '\0'; i++) {
        SBUF = str[i];   // Load the character to be sent into the serial buffer
        while (!TI);     // Wait for transmission to complete
        TI = 0;          // Clear the transmit interrupt flag
    }
}

void main(void) {
    char str[] = "The earth is one, don’t divide it. ";

    P2 = 0x00;   // Initialize Port 2
    init_serial();   // Initialize serial communication

    while (1) {
        send(str);   // Send the string repeatedly
    }
}
