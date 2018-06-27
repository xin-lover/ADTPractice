#include "treap.h"
#include "fatal.h"

#include <stdlib.h>

Position NullNode = NULL;

struct TreapNode
{
		ElementType element;
		Treap left;
		Treap right;
		int priority;
};

Treap Initialize()
{
		if(NullNode == NULL)
		{
				NullNode = malloc(sizeof(struct TreapNode));
				if(NullNode == NULL)
				{
						FatalError("out of space");
				}

				NullNode->left = NullNode->right = NullNode;
				NullNode->priority = Infinity;

		}

		return NullNode;
}

int Random()
{
		return rand() - 1;
}

Treap MakeEmpty(Treap t)
{
		if(t != NullNode)
		{
				MakeEmpty(t->left);
				MakeEmpty(t->right);
				free(t);
		}

		return NullNode;
}

void PrintTree(Treap t)
{
		if(t != NullNode)
		{
				printf("%d %d\n",t->element,t->priority);
				printf("left ");
				PrintTree(t->left);
				printf("\nright ");
				PrintTree(t->right);
				printf("\n");
		}
		return;

		if(t != NullNode)
		{
				PrintTree(t->left);
				printf("%d\n",t->element);
				PrintTree(t->right);
		}
}

Position Find(ElementType x, Treap t)
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

Position FindMin(Treap t)
{
		if(t == NullNode)
		{
				return NullNode;
		}
		else if(t->left == NullNode)
		{
				return t;
		}
		else
		{
				return FindMin(t->left);
		}
}

Position FindMax(Treap t)
{
		if(t != NullNode)
		{
				while(t->right != NullNode)
				{
						t = t->right;
				}
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

Treap Insert(ElementType item, Treap t)
{
		if(t == NullNode)
		{
				t = malloc(sizeof(struct TreapNode));
				if(t == NULL)
				{
						FatalError("out of space");
				}
				else
				{
						t->element = item;
						t->priority = Random();
						t->left = t->right = NullNode;
				}
		}
		else if(item < t->element)
		{
				t->left = Insert(item, t->left);
				if(t->left->priority < t->priority)
				{
						t = SingleRotateWithLeft(t);
				}
		}
		else if(item > t->element)
		{
				t->right = Insert(item,t->right);
				if(t->right->priority < t->priority)
				{
						t = SingleRotateWithRight(t);
				}
		}
		/*otherwise it's a duplicate:do nothing*/

		return t;
}

Treap Remove(ElementType item, Treap t)
{
		if(t != NullNode)
		{
				if(item < t->element)
				{
						t->left = Remove(item,t->left);
				}
				else if(item > t->element)
				{
						t->right = Remove(item,t->right);
				}
				else
				{
						/*Match found*/
						if(t->left->priority < t->right->priority)
						{
								t = SingleRotateWithLeft(t);
						}
						else
						{
								t = SingleRotateWithRight(t);
						}

						if(t != NullNode)
						{
								t = Remove(item,t);
						}
						else
						{
								free(t->left);
								t->left = NullNode;
						}
				}
		}

		return t;
}

ElementType Retrieve(Position p)
{
		return p->element;
}
