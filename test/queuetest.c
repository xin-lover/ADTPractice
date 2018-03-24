#include "../queue.h"
//#include "../fatal.h"
#include <stdio.h>


int main()
{
		Queue q = CreateQueue(16);
		Enqueue(10,q);
		Enqueue(11,q);
		Enqueue(12,q);
		printf("%d\n",Front(q));
		Dequeue(q);
		printf("%d\n",Front(q));
		printf("%d\n",FrontAndDequeue(q));
		printf("%d\n",Front(q));
		printf("%d\n",IsEmpty(q));
		MakeEmpty(q);
		printf("%d\n",IsEmpty(q));
		
		return 0;
}
