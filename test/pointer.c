#include <stdio.h>

int main()
{
	int *p = (int*)malloc(sizeof(int));
	*p = 10;
	free(p);
	double *y = (int*)malloc(sizeof(double));
	*y=2;
	
	printf("%d\n",p);
	printf("%d\n",y);
	printf("%d\n",p + 1);
	
	printf("%d\n",*(p + 1));
	printf("%f\n",*y);
	return 0;
}
