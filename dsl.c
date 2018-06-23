#include "skiplist.h"
#include "fatal.h"
#include <stdlib.h>

struct SkipNode
{
		ElementType element;
		SkipList right;
		SkipList down;
};

static Position bottom = NULL;
static Position tail = NULL;

SkipList Initialize()
{
		SkipList L;

		if(bottom == NULL)
		{
				bottom = malloc(sizeof(struct SkipNode));
				if(bottom == NULL)
				{
						FatalError("out of space");
				}

				bottom->right = bottom->down = bottom;

				tail = malloc(sizeof(struct SkipNode));
				if(tail == NULL)
				{
						FatalError("out of space");
				}
				tail->element = Infinity;
				tail->right = tail;
		}

		L = malloc(sizeof(struct SkipNode));
		if(L == NULL)
		{
				FatalError("out of space");
		}

		L->element = Infinity;
		L->right = tail;
		L->down = bottom;

		return L;
}

void Output(ElementType element)
{
		printf("%d\n",element);
}

SkipList MakeEmpty(SkipList L)
{
		L->right = tail;
		L->down = bottom;

		return L;
}

Position Find(ElementType item, SkipList L)
{
		Position current = L;
		while(item != current->element)
		{
				if(item < current->element)
				{
						current = current->down;
				}
				else
				{
						current = current->right;
				}
		}

		return current;
}

Position FindMin(SkipList L)
{
		Position current = L;

		while(current->down != bottom)
		{
				current = current->down;
		}

		return current;
}

Position FindMax(SkipList L)
{
		Position current = L;

		while(current->right->right != tail ||
						current->down != bottom)
		{
				if(current->right->right != tail)
				{
						current = current->right;
				}
				else
				{
						current = current->down;
				}
		}

		return current;
}

SkipList Insert(ElementType item, SkipList L)
{
		Position current = L;
		Position newNode;

		bottom->element = item;
		while(current != bottom)
		{
				while(item > current->element)
				{
						current = current->right;
				}

				if(current->element > current->down->right->right->element)
				{
						newNode = malloc(sizeof(struct SkipNode));
						if(newNode == NULL)
						{
								FatalError("out of space");
						}

						newNode->right = current->right;
						newNode->down = current->down->right->right;
						current->right=newNode;
						newNode->element = current->element;
						current->element = current->down->right->element;
				}
				else
				{
						current = current->down;
				}
		}

		printf("bbbbbbbbbb\n");
		if(L->right != tail)
		{
				newNode = malloc(sizeof(struct SkipNode));
				if(newNode == NULL)
				{
						FatalError("out of space");
				}

				newNode->down = L;
				newNode->right = tail;
				newNode->element = Infinity;
				L = newNode;
				printf("rr %d\n",L->element);
		}

		return L;
}

SkipList Remove(ElementType item, SkipList L)
{
		printf("remove is unimplemented");
		if(item)
		{
				return L;
		}

		return L;
}

ElementType Retrieve(Position P)
{
		return P->element;
}

