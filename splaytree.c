#include "splaytree.h"
#include "fatal.h"
#include <stddef.h>

struct SplayNode
{
	ElementType value;
	SplayTree left;
	SplayTree right;
};

typedef struct SplayNode *Position;
static Position NullNode = NULL; /*needs initialize*/

#define NegInfinity (-30000)
#define Infinity 30000

static SplayTree Splay(ElementType X, SplayTree T);

SplayTree Initialize()
{
	if(NullNode == NULL)
	{
		NullNode = (struct SplayNode*)malloc(sizeof(struct SplayNode));
		if(NullNode == NULL)
		{
			Error("out of space.\n");
			exit(1);
		}
	}

	NullNode->left = NullNode->right = NULL;
	return NullNode;
}

SplayTree MakeEmpty(SplayTree T)
{
	if(T != NullNode)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}

	return T;
}

void PrintTree(SplayTree T)
{
	if(T!=NullNode)
	{
		PrintTree(T->left);
		PrintTree(T->right);
		printf("%d\n",Retrieve(T));
	}
}

SplayTree Find(ElementType X, SplayTree T)
{
	return Splay(X,T);
}

SplayTree FindMin(SplayTree T)
{
	return Splay(NegInfinity, T);
}

SplayTree FindMax(SplayTree T)
{
	return Splay(Infinity, T);
}

static Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	K1 = K2->left;
	K2->left = K1->right;
	K1->right = K2;

	return K1;
}

static Position SingleRotateWithRight(Position K1)
{
	Position K2;
	K2 = K1->right;
	K1->right = K2->left;
	K2->left = K2;
	return K2;
}

SplayTree Splay(ElementType item, Position X)
{
	static struct SplayNode header;
	Position leftTreeMax,rightTreeMin;

	header.left = header.right = NullNode;
	leftTreeMax = rightTreeMin = &header;
	NullNode ->value = item;

	while(item != X->value)
	{
		if(item < X->value)
		{
			if(item < X->left->value)
			{
				X =  SingleRotateWithLeft(X);
			}
			if(X->left == NullNode)
			{
				break;
			}

			/* Link right */
			rightTreeMin->left =X;
			rightTreeMin = X;
			X = X->left;
		}
		else
		{
			if(item > X->right->value)
			{
				X = SingleRotateWithRight(X);
			}
			if(X->right == NullNode)
			{
				break;
			}

			/* Link left */
			leftTreeMax->right = X;
			leftTreeMax = X;
			X = X->right;
		}
	} /* while item != X->value */

	/* Reassemble */
	leftTreeMax->right = X->left;
	rightTreeMin->left = X->right;
	X->left = header.right;
	X->right = header.left;

	return X;
}

SplayTree Insert(ElementType item, SplayTree T)
{
	static Position NewNode=NULL;

	if(NewNode == NULL)
	{
		NewNode = (struct SplayNode*)malloc(sizeof(struct SplayNode));
		if(NewNode== NULL)
		{
			FatalError("out of space\n");
		}

		NewNode->value = item;

		if(T == NullNode)
		{
			NewNode->left = NewNode->right = NullNode;
			T = NewNode;
		}
		else
		{
			T = Splay(item,T);
			if(item < T->value)
			{
				NewNode->left = T->left;
				NewNode->right = T;
				T->left = NullNode;
				T = NewNode;

			}
			else if(T->value < item)
			{
				NewNode->right = T->right;
				NewNode->left = T;
				T->right = NullNode;
				T = NewNode;
			}
			else
			{
				return T;/*already in the tree*/
			}
		}

	}
	NewNode = NULL;
	return T;
}

SplayTree Remove(ElementType item, SplayTree T)
{
	Position NewTree;

	if(T != NullNode)
	{
		T = Splay(item, T);
		if(item == T->value)
		{
			/*found it!*/
			if(T->left == NullNode)
			{
				NewTree = T->right;
			}
			else
			{
				NewTree = T->left;
				NewTree = Splay(item,NewTree);
				NewTree->right = T->right;
			}

			free(T);
			T= NewTree;
		}
	}

	return T;
}

ElementType Retrieve(SplayTree T)
{
	return T->value;
}

