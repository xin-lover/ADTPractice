#include "kdtree.h"
#include "fatal.h"

struct KdNode
{
		ItemType data;
		KdTree left;
		KdTree right;
};

static KdTree RecursiveInsert(ItemType item,KdTree t,int level)
{
		if(t == NULL)
		{
				t = malloc(sizeof(struct KdNode));
				if(t == NULL)
				{
						FatalError("out of space");
				}

				t->left = t->right = NULL;
				t->data[0] = item[0];
				t->data[1] = item[1];
		}
		else if(item[level] < t->data[level])
		{
				t->left = RecursiveInsert(item,t->left,!level);
		}
		else
		{
				t->right = RecursiveInsert(item,t->right,!level);
		}

		return t;
		
}

KdTree Insert(ItemType item, KdTree t)
{
		return RecursiveInsert(item,t,0);
}

static void RecPrintRange(ItemType low, ItemType high, KdTree t, int level)
{
		if(t != NULL)
		{
				if(low[0] <= t->data[0] && t->data[0] <= high[0]
								&& low[1] <= t->data[1]
								&& t->data[1] <= high[1])
				{
						printf("(%d,%d)\n",t->data[0],t->data[1]);
				}

				if(low[level] <= t->data[level])
				{
						RecPrintRange(low,high,t->left,!level);
				}

				if(high[level] >= t->data[level])
				{
						RecPrintRange(low,high,t->right,!level);
				}
		}
}

void PrintRange(ItemType low, ItemType high,KdTree t)
{
		RecPrintRange(low,high,t,0);
}
