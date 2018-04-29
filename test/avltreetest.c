#include "../avltree.h"
#include <stdio.h>

int main()
{
	AVLTree t = NULL;
	t = Insert(1,t);
	printf("b:%d\n",Retrieve(FindMin(t)));
	t = Insert(2,t);
	t = Insert(3,t);
	t = Insert(4,t);
	printf("c:%d\n",Retrieve(FindMin(t)));

	return 0;
}
