#include "../stack.h"
#include <stdio.h>

int main()
{

		Stack s = CreateStack(16);
		Push(10,s);
		Push(11,s);
		Push(12,s);
		printf("%d\n",Top(s));
		Pop(s);
		printf("%d\n",Top(s));
		Pop(s);
		printf("%d\n",Top(s));
		
		return 0;
}
