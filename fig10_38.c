#include <stdio.h>

typedef double Matrix[2][2];

void MatrixMultiply(Matrix A,Matrix B, Matrix C,int n)
{
		int i,j,k;

		for(i=0;i<n;i++)
		{
				for(j = 0;j<n;j++)
				{
						C[i][j] = 0;
				}
		}

		for(i=0;i<n;i++)
		{
				for(j=0;j<n;j++)
				{
						for(k=0;k<n;k++)
						{
								C[i][j] += A[i][k] * B[k][j];
						}
				}
		}
}

int main()
{
		Matrix a = {{1,2},{3,4}};
		Matrix c;

		MatrixMultiply(a,a,c,2);

		printf("%6.2f %6.2f\n%6.2f %6.2f\n",c[0][0],c[0][1],
						c[1][0],c[1][1]);

		return 0;
}
