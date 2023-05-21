#include<reg51.h>

// Tx uC1

#define N (4)  // Define the length of the message

void main(void){
        unsigned char i;  // Declare a variable to hold the index of the character being sent
        char str[N] = {'Y','E','S',' '};  // Declare an array to hold the message

        TMOD = 0x20;  // Configure Timer 1 in mode 2
        TH1 = -3;     // Set Timer 1's reload value to -3 (9600 baud at 11.0592 MHz)
        SCON = 0x50;  // Configure the serial port for mode 1
        TR1 = 1;      // Start Timer 1

        i = 0;  // Initialize the index variable to 0
        while(1){  // Loop forever
                SBUF = str[i];  // Load the next character to send into the serial buffer
                while(TI==0);   // Wait for the transmission to complete
                TI = 0;         // Clear the transmit interrupt flag
                i = (i+1)%N;    // Increment the index and wrap around to the beginning of the message
        }
}
