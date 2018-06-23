#include <stdio.h>

#ifndef _DISJSETS_H
#define _disjsets_h

#define NUMSETS 128

typedef int DisjSet[NUMSETS + 1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet set);
void SetUnion(DisjSet set,SetType root1, SetType root2);
SetType Find(ElementType,DisjSet set);

#endif

void Initialize(DisjSet set)
{
		int i;
		for(i = NUMSETS;i>0;i--)
		{
				set[i] = 0;
		}
}

/*void SetUnion(DisjSet set, SetType root1, SetType root2)
{
		set[root2] = root1;
}*/

void SetUnion(DisjSet set, SetType root1, SetType root2)
{
		if(set[root2] < set[root1])
		{
				set[root1] = root2;
		}
		else
		{
				if(set[root1] == set[root2])
				{
						set[root1]--;
				}

				set[root2] = root1;
		}
}

/*SetType Find(ElementType x, DisjSet set)
{
		if(set[x] <= 0)
		{
				return x;
		}
		else
		{
				return Find(set[x],set);
		}
}*/

SetType Find(ElementType x, DisjSet set)
{
		if(set[x] <=0)
		{
				return x;
		}
		else
		{
				return set[x] = Find(set[x],set);
		}
}

int main()
{
		DisjSet set;
		int i;
		int j;
		int k;
		int set1;
		int set2;

		Initialize(set);
		j = k =1;
		while(k <= 8)
		{
				j = 1;
				while(j < NUMSETS)
				{
						set1 = Find(j,set);
						set2 = Find(j + k, set);
						SetUnion(set,set1,set2);
						j += 2 *k;
				}
				k *= 2;
		}
		
		i = 1;
		for(i = 1; i <NUMSETS; i++)
		{
				set1 = Find(i,set);
				printf("%d**",set1);
		}
		printf("\n");
		return 0;
}
