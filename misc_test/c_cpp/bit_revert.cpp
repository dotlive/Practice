#include <stdio.h>

int main()
{
	int a = 0x20;
	int b = ~a;
	printf("%0x\n", b);
	printf("%0x\n", a & b);

	return 0;
}
