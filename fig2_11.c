#include <stdio.h>

#define IsEven(N) ((n) % 2 == 0)

long int Pow(long int x, unsigned int n)
{
		if( n == 0)
		{
				return 1;
		}

		if(n == 1)
		{
				return x;
		}

		if(IsEven(n))
		{
				return Pow(x * x,n/2);
		}
		else
		{
				return Pow(x*x,n/2) * x;
		}
}

int main()
{
		printf("2^21 = %ld\n",Pow(2,21));
		return 0;
}
