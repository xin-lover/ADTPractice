#include <stdio.h>

#define NotAVertex (-1)

typedef int TwoDimArray[4][4];

void AllPairs(TwoDimArray A, TwoDimArray D, TwoDimArray Path,int n)
{
		int i,j,k;

		for(i = 0;i < n;++i)
		{
				for(j = 0; j < n; ++j)
				{
						D[i][j] = A[i][j];
						Path[i][j] = NotAVertex;
				}
		}

		for(k = 0;k < n;k++)
		{
				for(i=0;i<n;i++)
				{
						for(j = 0;j < n; j++)
						{
								if(D[i][k] + D[k][j] < D[i][j])
								{
										D[i][j] = D[i][k] + D[k][j];
										Path[i][j] = k;
								}
						}
				}
		}
}

int main()
{
		TwoDimArray A = {{0,2,-2,2},{1000,0,-3,1000},
					{4,1000,0,1000},{1000,-2,3,0}};
		
		TwoDimArray D,Path;
		int i,j;

		AllPairs(A,D,Path,4);

		for(i=0;i<4;i++)
		{
				for(j=0;j<4;j++)
				{
						printf("%6d",D[i][j]);
				}
				printf("\n");
		}

		printf("\n");
		for(i=0;i<4;i++)
		{
				for(j=0;j<4;j++)
				{
						printf("%6d",Path[i][j]);
				}

				printf("\n");
		}

		return 0;
}

