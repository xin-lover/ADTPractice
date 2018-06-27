#include <stdio.h>
#include <limits.h>

typedef long int TwoDimArray[5][5];
#define Infinity INT_MAX

void OptMatrix(const long C[], int n,TwoDimArray m, TwoDimArray lastChange)
{
		int i,k,left,right;
		long thism;

		for(left = 1; left <= n; left++)
		{
				m[left][left] = 0;
		}

		for(k=1;k<n;k++)
		{
				for(left = 1;left <= n-k;left++)
				{
						right = left + k;
						m[left][right] = Infinity;
						for(i = left; i < right;i++)
						{
								thism = m[left][i] + m[i + 1][right]
										+C[left - 1] * C[i] * C[right];

								if(thism < m[left][right])
								{
										m[left][right] = thism;
										lastChange[left][right] = i;
								}
						}
				}
		}
}

int main()
{
		long c[] = {50,10,40,30,5};

		long m[5][5],lastChange[5][5];

		int i,j;
		OptMatrix(c,4,m,lastChange);
		for(i=1;i<=4;i++)
		{
				for(j=1;j<=4;j++)
				{
						printf("%14d",m[i][j]);
				}

				printf("\n");
		}

		printf("\n");
		for(i=1;i<=4;i++)
		{
				for(j = 1;j<=4;j++)
				{
						printf("%14d",lastChange[i][j]);
				}

				printf("\n");
		}

		return 0;
}
