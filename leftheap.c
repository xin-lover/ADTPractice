#include "leftheap.h"
#include "fatal.h"

#include <stdlib.h>

struct TreeNode
{
		ElementType element;
		PriorityQueue left;
		PriorityQueue right;
		int npl;
};

PriorityQueue Initialize()
{
		return NULL;
}

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);

void SwapChildren(PriorityQueue H)
{
		PriorityQueue tmp;
		tmp = H->left;
		H->left = H->right;
		H->right = tmp;
}

ElementType FindMin(PriorityQueue H)
{
		if(IsEmpty(H))
		{
				Error("Priority queue is empty");
				return 0;
		}

		return H->element;
}

int IsEmpty(PriorityQueue H)
{
	return H== NULL;
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
		if(H1 == NULL)
		{
				return H2;
		}

		if(H2 == NULL)
		{
				return H1;
		}

		if(H1->element < H2->element)
		{
				return Merge1(H1,H2);
		}
		else
		{
				return Merge1(H2,H1);
		}
}

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
		if(H1->left == NULL)
		{
				H1->left = H2;
		}
		else
		{
				H1->right = Merge(H1->right,H2);
				if(H1->left->npl < H1->right->npl)
				{
						SwapChildren(H1);
				}

				H1->npl = H1->right->npl + 1;
		}

		return H1;

		
}

PriorityQueue Insert1(ElementType x, PriorityQueue H)
{
		PriorityQueue singleNode;

		singleNode = malloc(sizeof(struct TreeNode));
		if(singleNode == NULL)
		{
			FatalError("out of space");
		}
		else
		{
				singleNode->element = x;
				singleNode->npl = 0;
				singleNode->left = singleNode->right = NULL;
				H = Merge(singleNode, H);
		}

		return H;
}

PriorityQueue DeleteMin1(PriorityQueue H)
{
	PriorityQueue leftHeap;
	PriorityQueue rightHeap;

	if(IsEmpty(H))
	{
			Error("Priority queue is Empty");
			return H;
	}

	leftHeap = H->left;
	rightHeap = H->right;

	free(H);
	return Merge(leftHeap,rightHeap);
}
