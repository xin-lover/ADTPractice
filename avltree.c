#include "avltree.h"
#include "fatal.h"
#include <stddef.h>
#include <stdlib.h>

struct AVLNode
{
		ElementType element;
		AVLTree left;
		AVLTree right;
		int height;
};

AVLTree MakeEmpty(AVLTree T)
{
		if(T != NULL)
		{
				MakeEmpty(T->left);
				MakeEmpty(T->right);
				free(T);
		}

		return NULL;
}

static int Height(Position P)
{
		if(P == NULL)
		{
				return -1;
		}
		else
		{
				return P->height;
		}
}

static int Max(int Lhs, int Rhs)
{
		return Lhs > Rhs ? Lhs : Rhs;
}

static Position SingleRotateWithLeft(Position K2)
{
		Position K1;

		K1=K2->left;
		K2->left = K1->right;
		K1->right = K2;

		K2->height = Max(Height(K2->left),Height(K2->right)) + 1;
		K1->height = Max(Height(K1->left),K2->height) + 1;

		return K1;

}

static Position SingleRotateWithRight(Position K1)
{
		Position K2;
		K2 = K1->right;
		K1->right = K2->left;
		K2->left = K1;

		K1->height = Max(Height(K1->left), Height(K1->right)) + 1;
		K2->height = Max(Height(K2->right),K1->height) + 1;
		return K2;
}

static Position DoubleRotateWithLeft(Position K3)
{
		/* Rotate between K1 and K2 */
		K3->left = SingleRotateWithRight(K3->left);

		/* Rotate between K3 and K2 */
		return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K1)
{
		K1->right = SingleRotateWithLeft(K1->right);

		return SingleRotateWithRight(K1);
}
Position Find(ElementType X, AVLTree T)
{

		if(T == NULL)
		{
				return NULL;
		}

		if(X < T->element)
		{
				return Find(X, T->left);
		}
		else if(X > T->element)
		{
				return Find(X, T->right);
		}
		else
		{
				return T;
		}
		
}

Position FindMin(AVLTree T)
{
		if(T == NULL)
		{
				return NULL;
		}
		else if(T->left == NULL)
		{
				return T;
		}
		else
		{
				return FindMin(T->left);
		}
}

Position FindMax(AVLTree T)
{
		Position temp = T;
		if(temp == NULL)
		{
				return NULL;
		}

		while(temp->right != NULL)
		{
				if(temp->right != NULL)
				{
					temp = temp->right;
				}
		}

		return temp;
}

AVLTree Insert(ElementType X, AVLTree T)
{
		if(T == NULL)
		{
				T = (AVLTree)malloc(sizeof(struct AVLNode));
				if(T == NULL)
				{
						FatalError("out of memory\n");
						exit(1);
				}
				T->element = X;
				T->height =0;
				T->left = T->right = NULL;
		}
		else if(X > T->element)
		{
				T->right = Insert(X, T->right);
				if(Height(T->right) - Height(T->left) == 2)
				{
						if(X > T->right->element)
						{
								T=SingleRotateWithRight(T);
						}
						else
						{
								T=DoubleRotateWithRight(T);
						}
				}
		}
		else if(X < T->element)
		{
				T->left = Insert(X,T->left);
				if(Height(T->left) - Height(T->right) == 2)
				{
						if(X < T->left->element)
						{
								T=SingleRotateWithLeft(T);
						}
						else
						{
								T=DoubleRotateWithLeft(T);
						}
				}
		}

		T->height = Max(Height(T->left), Height(T->right)) + 1;
		return T;
}

AVLTree Delete(ElementType X, AVLTree T)
{
		Error("Not Implement");
		return T;
}

ElementType Retrieve(Position P)
{
		return P->element;
}

