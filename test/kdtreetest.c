#include "../kdtree.h"
#include <stdio.h>

int main()
{
		KdTree t;
		ItemType it,l,h;
		int i;

		printf("start program\n");

		t = NULL;

		for(i = 300;i < 370; ++i)
		{
				it[0] = i;
				it[1] = 2500 - i;
				t = Insert(it,t);
		}

		printf("Insertions complete\n");

		i = 1;
		l[0] = 70;
		l[1] = 2186;
		h[0] = 1200;
		h[1] = 2200;
		PrintRange(l,h,t);

		printf("done...\n");
		return 0;
}
