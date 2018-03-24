#include "list.h"
#include "fatal.h"
#include <stdlib.h>
#include <stdio.h>

List MakeEmpty(List L)
{
		if(L != NULL)
		{
				DeleteList(L);
		}
		L = (List)malloc(sizeof(struct Node));
		if(L == NULL)
		{
				FatalError("out of memory\n");
		}

		L->next = NULL;
		return L;
}

int IsEmpty(List L)
{
		return L->next == NULL;
}

int IsLast(Position P, List L)
{
		return P->next == NULL;
}

Position Find(ElementType value, List L)
{
	List temp = L->next;
	while(temp->element != value)
	{
			if(temp->next != NULL)
			{
					temp = temp->next;
			}
			else
			{
					break;
			}
	}

	return temp;
}

void Delete(ElementType X, List L)
{
	Position p = L;
	while(p->next != NULL && p->next->element != X)
	{
			p = p->next;
	}

	if(p->next != NULL)
	{
			Position beDel = p->next;
			p->next = beDel->next;
			free(beDel);
	}
}

Position FindPrevous(ElementType X, List L)
{
		Position temp = L;
		while(temp ->next != NULL && temp->next->element != X)
		{
				temp = temp->next;
		}

		return temp;
}

void Insert(ElementType X, List L,Position P)
{
	Position newNode = (Position)malloc(sizeof(struct Node));
	if(newNode == NULL)
	{
			FatalError("out of memory\n");
	}
	newNode->element = X;
	newNode->next = P->next;
	P->next = newNode;
}

void DeleteList(List L)
{
		Position temp = L->next;
		L->next = NULL;
		while(temp != NULL)
		{
				Position p = temp;
				temp = temp->next;
				free(p);
		}
}

Position Header(List L)
{
		return L;
}

Position First(List L)
{
		return L->next;
}

Position Advance(Position P)
{
		return P->next;
}

ElementType Retrieve(Position P)
{
		return P->element;
}


