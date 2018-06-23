#include "redblack.h"
#include "fatal.h"
#include <stdlib.h>

typedef enum ColorType
{
		Red,
		Black
}ColorType;

struct RedBlackNode
{
		ElementType element;
		RedBlackTree left;
		RedBlackTree right;
		ColorType color;
};

static Position NullNode = NULL;

RedBlackTree Initialize()
{
		RedBlackTree t;
		if(NullNode == NULL)
		{
				NullNode = malloc(sizeof(struct RedBlackNode));
				if(NullNode == NULL)
				{
						FatalError("out of space");
				}
				NullNode->left = NullNode->right = NullNode;
				NullNode->color = Black;
				NullNode->element = 12345;
		}

		t = malloc(sizeof(struct RedBlackNode));
		if(t == NULL)
		{
				FatalError("out of space");
		}

		t->element = NEGINFINITY;
		t->left = t->right = NullNode;
		t->color = Black;

		return t;
}

void Output(ElementType element)
{
		printf("%d\n",element);
}

static void DoPrint(RedBlackTree t)
{
		if(t != NullNode)
		{
				DoPrint(t->left);
				Output(t->element);
				DoPrint(t->right);
		}

}

void PrintTree(RedBlackTree t)
{
		DoPrint(t->right);
}

static RedBlackTree MakeEmptyRec(RedBlackTree t)
{
	if(t != NullNode)
	{
			MakeEmpty(t->left);
			MakeEmpty(t->right);
			free(t);
	}

	return NullNode;
}

RedBlackTree MakeEmpty(RedBlackTree t)
{
		t->right = MakeEmptyRec(t->right);
		return t;
}

Position Find(ElementType x, RedBlackTree t)
{
		if(t == NullNode)
		{
				return NullNode;
		}

		if(x < t->element)
		{
				return Find(x,t->left);
		}
		else if(x > t->element)
		{
				return Find(x,t->right);
		}
		else
		{
				return t;
		}
}

Position FindMin(RedBlackTree t)
{
		t = t->right;
		while(t->left != NullNode)
		{
				t = t->left;
		}

		return t;
}

Position FindMax(RedBlackTree t)
{
		while(t->right != NullNode)
		{
				t = t->right;
		}

		return t;
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
		K2->left = K1;

		return K2;
}

static Position Rotate(ElementType item, Position parent)
{
		if(item < parent->element)
		{
				return parent->left = item < parent->left->element ?
						SingleRotateWithLeft(parent->left) :
						SingleRotateWithRight(parent->left);
		}
		else
		{
				return parent->right = item < parent->right->element ?
						SingleRotateWithLeft(parent->right) :
						SingleRotateWithRight(parent->right);
		}
}

static Position X,p,gp,ggp;

static void HandleReorient(ElementType item,RedBlackTree t)
{
		X->color = Red;
		X->left->color = Black;
		X->right->color = Black;

		if(p->color == Red)
		{
				gp->color = Red;
				if((item < gp->element) != (item < p->element))
				{
					p = Rotate(item,gp);
				}

				X = Rotate(item,ggp);
				X->color = Black;
		}

		t->right->color = Black;
}

RedBlackTree Insert(ElementType item,RedBlackTree t)
{
		X = p = gp = t;
		NullNode->element = item;
		while(X->element != item)
		{
				ggp = gp;
				gp =p;
				p = X;
				if(item < X->element)
				{
						X = X->left;
				}
				else
				{
						X = X->right;
				}

				if(X->left->color == Red && X->right->color == Red)
				{
						HandleReorient(item,t);
				}
		}

		if(X != NullNode)
		{
				return NullNode;
		}

		X = malloc(sizeof(struct RedBlackNode));
		if(X == NULL){
				FatalError("out of space.");
		}

		X->element = item;
		X->left = X->right = NullNode;

		if(item < p->element)
		{
				p->left = X;
		}
		else
		{
				p->right = X;
		}

		HandleReorient(item,t);

		return t;
}

RedBlackTree Remove(ElementType item,RedBlackTree t)
{
		printf("remove is unimplemented\n");
		if(item)
		{
				return t;
		}

		return t;
}

ElementType Retrieve(Position p)
{
		return p->element;
}

