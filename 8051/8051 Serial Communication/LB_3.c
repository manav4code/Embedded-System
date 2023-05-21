#include<reg51.h>

// Define a constant number NUM as 0x44 (in binary: 0100 0100)
#define NUM (0x44)

// Define a single bit for P1_0 using bit-addressing syntax
sbit P1_0 = P1^0;

void main(void){
    // Declare a variable i and initialize it to 0
    unsigned char i = 0;

    // Loop forever
    while(1){
        // Set P1_0 to the i-th bit of NUM (from LSB to MSB)
        P1_0 = NUM & (1<<i);
        // Increment i and wrap around to 0 if it exceeds 7
        i = (i+1)%8;
    } 

    // The return statement is not strictly necessary, as the main function does not return a value
    return;
}
