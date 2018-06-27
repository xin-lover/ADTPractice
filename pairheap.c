#include "pairheap.h"
#include "fatal.h"
#include <stdlib.h>

#define MaxSiblings 1000

struct PairNode
{
		ElementType element;
		Position leftChild;
		Position nextSibling;
		Position prev;
};

Position CompareAndLink(Position first, Position second);
PairHeap CombineSiblings(Position FirstSibling);

PairHeap Initialize()
{
		return NULL;
}

PairHeap MakeEmpty(PairHeap H)
{
		if(H != NULL)
		{
				MakeEmpty(H->leftChild);
				MakeEmpty(H->nextSibling);
				free(H);
		}

		return NULL;
}

PairHeap Insert(ElementType item,PairHeap H,Position *loc)
{
		Position newNode;

		newNode = malloc(sizeof(struct PairNode));
		if(newNode == NULL)
		{
				FatalError("out of space");
		}

		newNode->element = item;
		newNode->leftChild = newNode->nextSibling = NULL;
		newNode->prev = NULL;

		*loc = newNode;
		if(H == NULL)
		{
				return newNode;
		}
		else
		{
				return CompareAndLink(H,newNode);
		}
}

PairHeap DecreaseKey(Position p, ElementType delta,PairHeap H)
{
		if(delta < 0)
		{
				Error("Decrease called with negtive delta");
		}

		p->element -= delta;
		if(p == H)
		{
				return H;
		}

		if(p->nextSibling != NULL)
		{
				p->nextSibling->prev = p->prev;
		}

		if(p->prev->leftChild == p)
		{
				p->prev->leftChild = p->nextSibling;
		}
		else
		{
				p->prev->nextSibling = p->nextSibling;
		}

		p->nextSibling = NULL;

		return CompareAndLink(H,p);
}

PairHeap DeleteMin(ElementType *minItem,PairHeap H)
{
		Position newRoot = NULL;

		if(IsEmpty(H))
		{
				Error("Pairing heap is empty");
		}
		else
		{
				*minItem = H->element;
				if(H->leftChild != NULL)
				{
						newRoot = CombineSiblings(H->leftChild);
				}

				free(H);
		}

		return newRoot;
}

Position CompareAndLink(Position first, Position second)
{
		if(second == NULL)
		{
				return first;
		}
		else if(first->element <= second->element)
		{
				second->prev = first;
				first->nextSibling = second->nextSibling;
				if(first->nextSibling != NULL)
				{
						first->nextSibling->prev = first;
				}

				second->nextSibling = first->leftChild;
				if(second->nextSibling != NULL)
				{
						second->nextSibling->prev = second;
				}

				first->leftChild = second;
				return first;
		}
		else
		{
				second->prev = first->prev;
				first->prev = second;

				first->nextSibling = second->leftChild;
				if(first->nextSibling != NULL)
				{
						first->nextSibling->prev = first;
				}

				second->leftChild = first;
				return second;
		}
}

PairHeap CombineSiblings(Position firstSibling)
{
		static Position treeArray[MaxSiblings];
		int i,j,numSiblings;

		if(firstSibling->nextSibling == NULL)
		{
				return firstSibling;
		}

		for(numSiblings =0; firstSibling != NULL;numSiblings++)
		{
				treeArray[numSiblings] = firstSibling;
				firstSibling->prev->nextSibling = NULL;
				firstSibling = firstSibling->nextSibling;
		}

		treeArray[numSiblings] = NULL;

		for(i = 0;i +1 < numSiblings;i+=2)
		{
				treeArray[i] = CompareAndLink(treeArray[i],treeArray[i+1]);
		}

		j = i-2;
		if(j == numSiblings -3)
		{
				treeArray[j] = CompareAndLink(treeArray[j],treeArray[j+2]);
		}

		for(;j>=2;j-=2)
		{
				treeArray[j-2] = CompareAndLink(treeArray[j-2],treeArray[j]);
		}

		return treeArray[0];
}

ElementType FindMin(PairHeap H)
{
		if(IsEmpty(H))
		{
				return H->element;
		}

		Error("Priority queue is empty");
		return 0;
}

int IsEmpty(PairHeap H)
{
		return H== NULL;
}

int IsFull(PairHeap H)
{
		return 0;
}

void Destroy(PairHeap H)
{
		MakeEmpty(H);
}
