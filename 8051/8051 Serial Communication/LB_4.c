#include<reg51.h>

// Define a constant number NUM as 0x44 (in binary: 0100 0100)
#define NUM (0x44)

// Define a single bit for P1_3 using bit-addressing syntax
sbit P1_3 = P1^3;

void main(void){
    // Declare a variable i and initialize it to 7 (the MSB of an 8-bit value)
    unsigned char i = 7;

    // Do-while loop: execute the body at least once, and then repeat as long as i is non-zero
    do
    {
        // Set P1_3 to the i-th bit of NUM (from MSB to LSB)
        P1_3 = NUM & (1<<i);
        // Decrement i
        i--;
    } while (i);

    // The return statement is not strictly necessary, as the main function does not return a value
    return;
}
