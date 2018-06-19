#include "../leftheap.h"

#include <stdio.h>

int main()
{
		PriorityQueue H;
		H = Initialize();
		Insert(2,H);
		Insert(1,H);
		Insert(5,H);
		Insert(3,H);

		while(!IsEmpty(H))
		{
				printf("%d\n",DeleteMin(H));
		}
		return 0;
}
