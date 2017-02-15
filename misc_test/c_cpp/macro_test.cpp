#include <stdio.h>

#define AA 0x20
#define BB ~(AA)

int main()
{
	printf("A = %x\n", AA);
	printf("B = %x\n", BB);
	return 0;
}
