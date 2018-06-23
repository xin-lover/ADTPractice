#include <stdio.h>

int Bad(unsigned int n)
{
		if(n == 0)
		{
				return 0;
		}
		else
		{
				return Bad(n / 3 + 1) + n - 1;
		}
}

int main()
{
		Bad(10);
		printf("Bad is infinite recursion\n");
		return 0;
}
