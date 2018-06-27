#include "../aatree.h"
#include <stdio.h>

#define NumItems 20

int main()
{
		AATree t;
		Position p;
		int i;
		int j=0;

		t = Initialize();
		t = MakeEmpty(NullNode);

		t = Insert(1,t);
		t = Insert(2,t);
		t = Insert(3,t);
		t = Insert(4,t);
		t = Insert(5,t);
		t = Insert(6,t);
		t = Insert(7,t);

		t = Remove(4,t);

		PrintTree(t);
		return 0;

		for(i=0;i < NumItems;i++,j = (j + 7) % NumItems)
		{
				t = Insert(j,t);
		}

		for(i =0 ;i < NumItems;i++)
		{
				if((p = Find(i,t)) == NullNode || Retrieve(p) != i)
				{
						printf("Error at %d\n",i);
				}
		}


		for(i = 0;i < NumItems; i+=2)
		{
				t = Remove(i,t);
		}

		for(i = 0;i < NumItems;i++)
		{
				printf("%d\n",Retrieve(Find(i,t)));
		}
		for(i = 1;i < NumItems;i+=2)
		{
				if((p = Find(i,t)) == NullNode || Retrieve(p) != i)
				{
						printf("Error2 at %d\n",i);
				}
		}

		for(i = 0;i < NumItems; i+=2)
		{
				if((p = Find(i,t)) != NullNode)
				{
						printf("Error3 at %d\n",i);
				}
		}

		printf("Min is %d, Max is %d\n",Retrieve(FindMin(t)),Retrieve(FindMax(t)));

		return 0;
}
