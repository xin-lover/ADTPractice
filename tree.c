#include "tree.h"
#include "fatal.h"
#include <stddef.h>
#include <stdlib.h>

struct TreeNode
{
		ElementType element;
		SearchTree left;
		SearchTree right;
};

SearchTree MakeEmpty(SearchTree T)
{
		if(T != NULL)
		{
				MakeEmpty(T->left);
				MakeEmpty(T->right);
				free(T);
		}

		return NULL;
}

Position Find(ElementType X, SearchTree T)
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

Position FindMin(SearchTree T)
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

Position FindMax(SearchTree T)
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

SearchTree Insert(ElementType X, SearchTree T)
{
		if(T == NULL)
		{
				T = (SearchTree)malloc(sizeof(struct TreeNode));
				if(T == NULL)
				{
						FatalError("out of memory\n");
						exit(1);
				}
				T->element = X;
				T->left = T->right = NULL;
		}
		else if(X > T->element)
		{
				T->right = Insert(X, T->right);
		}
		else if(X < T->element)
		{
				T->left = Insert(X,T->left);
		}

		return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
		Position tempCell;
		if(T == NULL)
		{
				Error("Element not found\n");
		}
		else if(X < T->element)
		{
				T->left = Delete(X,T);
		}
		else if(X > T->element)
		{
				T->right = Delete(X,T);
		}
		else if(T->left && T->right)
		{
			tempCell = FindMin(T->right);
			T->element=tempCell->element;
			T->right = Delete(T->element,T->right);
		}
		else
		{
				tempCell = T;
				if(T->left == NULL)
				{
						T= T->right;
				}
				else if(T->right == NULL)
				{
						T = T->left;
				}
				free(tempCell);
		}

		return T;
}

ElementType Retrieve(Position P)
{
		return P->element;
}
