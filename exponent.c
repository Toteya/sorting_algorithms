#include <stdio.h>

int exponent(int a, int b);

int main(void)
{
	int a = 3;
	int b = 2;

	printf("%d ^ %d = %d\n", a, b, exponent(a, b));
	return (0);
}

int exponent(int a, int b)
{
	if (b < 1)
		return 1;
	return a * exponent(a, b - 1);
}
