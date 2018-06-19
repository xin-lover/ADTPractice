#include "../splaytree.h"
#include <stdio.h>

int main()
{
	SplayTree t = Initialize();
	t = Insert(1,t);
	t = Insert(2,t);
	t = Insert(3,t);
	t = Insert(9,t);
	t = Insert(12,t);

	printf("%d\n",Retrieve(FindMin(t)));
	printf("%d\n",Retrieve(FindMax(t)));
	return 0;	
}
