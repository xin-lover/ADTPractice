#include "../binomial.h"
#include <stdio.h>

#define MaxSize 12000

int main()
{
		BinQueue q;
		int i;
		int j;
		ElementType anItem;

		q = Initialize();
		for(i = 0, j=MaxSize / 2; i <MaxSize;i++,j=(j+71) % MaxSize)
		{
				if(j < 10)
					printf("%d\n",j);
				q= Insert(j,q);
		}

		j = 0;
		while(!IsEmpty(q))
		{
				if(DeleteMin(q) != j++)
				{
						
						printf("Error in DeleteMin, %d\n",j);
				}
		}

		if(j != MaxSize)
		{
				printf("Error in counting\n");
		}
		printf("Done....\n");
		return 0;
}
