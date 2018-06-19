#include "binomial.h"
#include "fatal.h"

#include <stdlib.h>

typedef struct BinNode *Position;

struct BinNode
{
		ElementType element;
		Position leftChild;
		Position nextSibling;
};

struct Collection
{
		int currentSize;
		BinTree theTrees[MAXTREES];
};

BinQueue Initialize()
{
		BinQueue H;

		H = malloc(sizeof(struct Collection));
		if(H == NULL)
		{
				FatalError("out of space");
		}

		int i;
		for(i = 0;i < MAXTREES;++i)
		{
				H->theTrees[i] = NULL;
		}

		H->currentSize = 0;

		return H;
}

static void DestroyTree(BinTree T)
{
		if(T != NULL)
		{
				DestroyTree(T->leftChild);
				DestroyTree(T->nextSibling);
				free(T);
		}
}

void Destroy(BinQueue H)
{
		int i;
		for(i = 0;i < MAXTREES; ++i)
		{
			DestroyTree(H->theTrees[i]);
		}
}

BinQueue MakeEmpty(BinQueue H)
{
		Destroy(H);
		int i;
		for(i = 0;i < MAXTREES;++i)
		{
			H->theTrees[i] = NULL;	
		}

		H->currentSize = 0;

		return H;
}

BinQueue Insert(ElementType item, BinQueue H)
{
		BinTree newNode;
		BinQueue oneItem;

		newNode = malloc(sizeof(struct BinNode));
		if(newNode == NULL)
		{
				FatalError("out of space");
		}

		newNode->leftChild = newNode->nextSibling = NULL;
		newNode->element = item;

		oneItem = Initialize();
		oneItem->currentSize = 1;
		oneItem->theTrees[0] = newNode;

		return Merge(H,oneItem);
}

ElementType DeleteMin(BinQueue H)
{
		int i;
		int j;
		int minTree;

		BinQueue deletedQueue;
		Position deletedTree;
		Position oldRoot;
		ElementType minItem;

		if(IsEmpty(H))
		{
				Error("Empty binormial");
				return -Infinity;
		}

		minItem = Infinity;
		for(i = 0;i < MAXTREES;++i)
		{
				if(H->theTrees[i] && 
								H->theTrees[i]->element < minItem)
				{
						minItem = H->theTrees[i]->element;
						minTree = i;
				}
		}

		deletedTree = H->theTrees[minTree];
		oldRoot = deletedTree;

		deletedTree = deletedTree->leftChild;
		free(oldRoot);

		deletedQueue = Initialize();
		deletedQueue->currentSize = (1 << minTree) - 1;
		for( j = minTree - 1; j >= 0; j-- )
		{
			deletedQueue->theTrees[j] = deletedTree;
			deletedTree = deletedTree->nextSibling;
			deletedQueue->theTrees[j]->nextSibling = NULL;
		}

		H->theTrees[minTree] = NULL;
		H->currentSize -= deletedQueue->currentSize + 1;

		Merge(H,deletedQueue);
		return minItem;
}

ElementType FindMin(BinQueue H)
{
		int i;

		ElementType minItem;

		if(IsEmpty(H))
		{
				Error("Empty binormial");
				return 0;
		}

		minItem = Infinity;
		for(i =0;i < MAXTREES;++i)
		{
				if(H->theTrees[i] &&
								H->theTrees[i]->element < minItem)
				{
						minItem = H->theTrees[i]->element;
				}
		}

		return minItem;
}

int IsEmpty(BinQueue H)
{
		return H->currentSize == 0;
}

int IsFull(BinQueue H)
{
		return H->currentSize = CAPACITY;
}

BinTree CombineTrees(BinTree t1, BinTree t2)
{
		if(t1->element > t2->element)
		{
				return CombineTrees(t2,t1);
		}

		t2->nextSibling = t1->leftChild;
		t1->leftChild = t2;
		return t1;
}

BinQueue Merge(BinQueue H1, BinQueue H2)
{
		BinTree t1;
		BinTree t2;
		BinTree carry = NULL;

		int i;
		int j;

		if(H1->currentSize + H2->currentSize > CAPACITY)
		{
				Error("Merge would exceed capacity");
		}

		H1->currentSize += H2->currentSize;

		for(i =0, j=1;j<=H1->currentSize;i++,j *= 2)
		{
				t1 = H1->theTrees[i];
				t2 = H2->theTrees[i];

				switch(!!t1 + 2 * !!t2 + 4 * !!carry)
				{
						case 0: /*No trees*/
						case 1: /*only H1*/
								break;
						case 2: /*only H2*/
								H1->theTrees[i] = t2;
								H2->theTrees[i] = NULL;
								break;
						case 4: /*only carry*/
								H1->theTrees[i] = carry;
								carry = NULL;
								break;
						case 3: /*H1 and H2*/
								carry = CombineTrees(t1,t2);
								H1->theTrees[i] = H2->theTrees[i] = NULL;
								break;
						case 5: /*H1 and carry*/
								carry = CombineTrees(t1, carry);
								H1->theTrees[i] = NULL;
								break;
						case 6: /*H2 and carry*/
								carry = CombineTrees(t2, carry);
								H2->theTrees[i] = NULL;
								break;
						case 7: /*all three*/
								H1->theTrees[i] = carry;
								carry = CombineTrees(t1,t2);
								H2->theTrees[i] = NULL;
								break;
						default:
								break;
				}
		}

		return H1;
}


