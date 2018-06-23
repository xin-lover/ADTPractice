#include "../splaytree.h"

#include <stdio.h>

#define NUMITEMS 500

int main()
{
		SplayTree t;
		SplayTree p;
		int i;
		int j = 0;

		t = Initialize();
		t = MakeEmpty(t);
		for(i = 0;i < NUMITEMS; ++i,j=(j+7)%NUMITEMS)
		{
				t = Insert(j,t);
		}

		for(j = 0;j < 2; j++)
		{
			for(i = 0;i <NUMITEMS;i++)
			{
					t = Find(i,t);
					if(Retrieve(t) != i)
					{
							printf("Error1 at %d\n",i);
					}
			}
		}

		printf("Entering remove\n");

		for(i=0;i<NUMITEMS;i+=2)
		{
				t = Remove(i,t);
		}

		for(i = 1; i <NUMITEMS;i+=2)
		{
				t = Find(i,t);
				if(Retrieve(t) != i)
				{
						printf("Error2 at %d\n",i);
				}
		}

		for(i=0;i < NUMITEMS;i+=2)
		{
				t = Find(i,t);
				if(Retrieve(t) == i)
				{
						printf("Error3 at %d\n",i);
				}
		}

		printf("Min is %d\n",Retrieve(t = FindMin(t)));
		printf("Max is %d\n",Retrieve(t = FindMax(t)));
		return 0;
}
