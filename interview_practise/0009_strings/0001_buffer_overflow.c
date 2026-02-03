#include <stdio.h>
#include <string.h>

void visual_overflow() {
	char test = 0xAB;
	char value = 0xCD;
	char buffer[10];
	// OVERFLOW
	printf("test : %X \n", test);
	printf("value : %X \n", value);
	strcpy(buffer, "0123456789012345678901234567890123456789"); // 20 bytes!
	printf("test : %X \n", test);
	printf("value : %X \n", value);
	printf("Buffer: %s\n", buffer);
}

int main() {
	visual_overflow();
	return 0;
}


/*
 * 1. Before the Overflow: Everything is as expected.
 x/xb &test -> 0xAB
 x/xb &value -> 0xCD
 x/10xb &buffer -> ... zeros ...*

2. After the Overflow: The memory layout is revealed!
 x/xb &test -> 0x31*
 x/xb &value -> 0x30*
 * */
