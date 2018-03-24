#include "../list.h"
#include <stddef.h>
#include <stdio.h>

int main()
{
		List list = NULL; 
		list = MakeEmpty(list);
		Insert(10,list,Header(list));
		Insert(11,list,Find(10,list));
		Insert(15,list,Find(11,list));
		printf("isEmpty %d\n",IsEmpty(list));
		printf("element 1:%d\n",Retrieve(First(list)));
		Position temp = list->next;
		while(temp != NULL)
		{
				printf("%d\n",Retrieve(temp));
				temp = temp->next;
		}
		return 0;
}
