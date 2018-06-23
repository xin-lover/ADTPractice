#include <stdio.h>

unsigned int Gcd(unsigned int m, unsigned int n)
{
		unsigned int rem;

		while(n > 0)
		{
				rem = m % n;
				m = n;
				n = rem;
		}

		return m;
}

int main()
{
		printf("Gcd(45,35) = %d\n",Gcd(45,35));
		printf("Gcd(1989,1590) = %d\n",Gcd(1989,1590));

		return 0;
}
