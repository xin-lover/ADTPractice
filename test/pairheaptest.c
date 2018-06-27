#include "../pairheap.h"
#include <stdio.h>

void Sleep(int x)
{
		int i,j,k,m;
		for(i = 0;i < 10000;++i)
		{
				for(j=0;j<1000;j++)
				{
						for(k=0;k<x;k++)
						{
								m++;
						}
				}
		}
		printf("Done sleeping!! %d",m);
}

#define MaxSize 500

int main()
{
		PairHeap H;
		Position p[MaxSize];

		int i,j;
		int anItem;

		H= Initialize();
		for(i = 0,j = MaxSize / 2; i < MaxSize;i++,j=(j+71)%MaxSize)
		{
				H=Insert(j+MaxSize,H,&p[j]);
		}

		printf("Done inserting\n");

		for(i = 0,j=MaxSize / 2; i < MaxSize;i++,j=(j+51)%MaxSize)
		{
				H=DecreaseKey(p[j],MaxSize,H);
		}

		j = 0;
		while(!IsEmpty(H))
		{
				if(((H=DeleteMin(&anItem,H)),anItem) != j++)
				{
						printf("Error in DeleteMin,%d\n",j);
				}
		}
		printf("done...\n");

		return 0;
}
