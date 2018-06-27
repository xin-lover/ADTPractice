#include "../treap.h"
#include <stdio.h>

#define NumItems 12000

int main()
{
		Treap t;
		Position p;
		int i;
		int j=0;

		t = Initialize();
		t = MakeEmpty(NullNode);

		for(i=0;i<NumItems;i++,j = (j + 7) % NumItems)
		{
				t = Insert(j,t);
		}

		for(i = 0;i < NumItems;i++)
		{
				if((p = Find(i,t)) == NullNode || Retrieve(p) != i)
				{
						printf("Errro1 at %d\n",i);
				}
		}

		for(i =0;i < NumItems; i+=2)
		{
				t = Remove(i,t);
		}

		for(i = 1; i < NumItems; i+=2)
		{
				if((p = Find(i,t)) == NullNode || Retrieve(p) != i)
				{
						printf("Error2 at %d\n",i);
				}
		}

		for(i = 0;i<NumItems;i+=2)
		{
				if((p = Find(i,t)) != NullNode)
				{
						printf("Error3 at %d\n",i);
				}
		}

		printf("Min is %d, Max is %d\n",Retrieve(FindMin(t)),Retrieve(FindMax(t)));

		return 0;
}

