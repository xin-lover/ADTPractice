#include <stdio.h>

static unsigned long seed = 1;

#define A 48271L
#define M 2147483647L

double Random()
{
		seed = (A * seed) % M;
		return (double)seed /M;
}

void Initialize(unsigned long initval)
{
		seed = initval;
}

int main()
{
		int i;
		for(i = 0;i < 20;i++)
		{
				printf("%6f\n",Random());
		}

		return 0;
}
