#include "../skiplist.h"
#include <stdio.h>

#define N 800

int main()
{
		SkipList t;
		Position p;

		int i;
		int j= 0;

		t = Initialize();
		t = MakeEmpty(t);

		/*for(i = 0;i < N; ++i,j = (j + 7) % N)
		{
				t = Insert(j,t);
		}*/
		t = Insert(5,t);
		t = Insert(10,t);
		t = Insert(15,t);
		t = Insert(20,t);
		t = Insert(25,t);
		t = Insert(30,t);
		t = Insert(35,t);

		printf("****************\n");
		t = Insert(27,t);
		/*printf("Insert are complete\n");

		for(i = 0;i < N; ++i)
		{
				if((p = Find(i, t)) == NULL || Retrieve(p) != i)
				{
						printf("Error at %d\n",i);
				}
		}

		printf("Min is %d, Max is %d\n", Retrieve(FindMin(t)),Retrieve(FindMax(t)));*/
		return 0;
}
