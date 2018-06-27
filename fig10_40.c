#include <stdio.h>

int Fib(int n)
{
		if(n <= 1)
		{
				return 1;
		}
		else
		{
				return Fib(n - 1) + Fib(n -2 );
		}
}

int Fibonacci(int n)
{
		int i,last,nextToLast,answer;

		if(n <= 1)
		{
				return 1;
		}

		last = nextToLast = 1;
		for(i = 2; i <= n; i++)
		{
				answer = last + nextToLast;
				nextToLast = last;
				last = answer;
		}

		return answer;
}

int main()
{
		printf("%d \n %d \n",Fib(7),Fibonacci(7));
		return 0;
}
