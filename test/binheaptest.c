#include "../binheap.h"

#include <stdio.h>

int main()
{
		PriorityQueue q;
		q = Initialize(32);
		Insert(1,q);
		Insert(3,q);
		Insert(29,q);
		Insert(10,q);
		
		while(!IsEmpty(q))
		{
				printf("%d\n",DeleteMin(q));
		}

		return 0;
}
