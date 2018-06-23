#include "../redblack.h"

#include <stdio.h>
#define N 800

int main()
{
		RedBlackTree t;
		Position p;
		int i;
		int j = 0;

		t = Initialize();
		t = MakeEmpty(t);

		for(i=0;i<N;i++,j=(j+7)%N)
		{
				t = Insert(j,t);
		}

		printf("Inserts are complete\n");

		for(i = 0;i < N; ++i)
		{
				if((p = Find(i,t)) == NULL || Retrieve(p) != i)
				{
					printf("Error at %d\n",i);
				}
		}

		printf("Min is %d,Max is %d\n",Retrieve(FindMin(t)),Retrieve(FindMax(t)));
		return 0;
}
