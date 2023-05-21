#include <reg51.h>

unsigned char input;
unsigned char high, low;

void convert_to_ascii(unsigned char input) {
 
	// Getting upper nibble
	high = input >> 4;
	
	// Masking lower nibble
  low = input & 0x0F;
  
	// ORing with 30H --> 48D
	high = high + 48;   
  low = low + 48;
}

void main(void) {
  while(1) {
    input = P0;  // take packed BCD number as input from port 0 
    convert_to_ascii(input);
    P1 = high;  // display high nibble on port 1
    P2 = low;  // display low nibble on port 2
  }
}
