#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"

double Eval(int n)
{
		int i;
		double sum;

		if( n == 0 )
		{
				return 1.0;
		}
		else
		{
				sum = 0.0;
				for(i = 0;i < n; i++)
				{
						sum += Eval(i);
				}

				return 2.0 * sum / n + n;
		}
}

double Eval2(int n)
{
		int i,j;
		double sum,answer;
		double *c;

		c = malloc(sizeof(double) * (n + 1));
		if(c == NULL)
		{
				FatalError("out of space");
		}

		c[0] = 1.0;
		for(i = 1;i<=n;i++)
		{
				sum = 0;
				for(j = 0;j<i;j++)
				{
						sum+=c[j];
				}

				c[i] = 2 * sum / i + i;
		}

		answer = c[n];
		free(c);

		return answer;
}

int main()
{
		printf("%f\n%f\n",Eval(10),Eval2(10));
		return 0;
}
