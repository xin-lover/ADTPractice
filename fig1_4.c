#include <stdio.h>

#define PrintDigit(ch) (putchar((ch) + '0'))

void PrintOut(unsigned int n)
{
		if(n >= 10)
		{
				PrintOut(n / 10);
		}

		PrintDigit(n % 10);
}

int main()
{
		PrintOut(1369);
		putchar('\n');
		return 0;
}
