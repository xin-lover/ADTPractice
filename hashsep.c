#include "hashsep.h"
#include "fatal.h"
#include <stdlib.h>

#define MinTableSize (10)

struct ListNode
{
		ElementType element;
		Position next;
};

typedef Position List;

struct HashTbl
{
		int tableSize;
		List *theLists;
};

static int NextPrime(int N)
{
		int i;

		if(N % 2 == 0)
		{
				N++;
		}

		for(;;N+=2)
		{
				for(i = 3; i * i <= N; i+=2)
				{
						if(N % i == 0)
						{
								goto ContOuter;
						}
				}

				return N;
ContOuter:;
		}
}

Index Hash(ElementType key, int tableSize)
{
	return key % tableSize;
}

HashTable InitializeTable(int tableSize)
{
		HashTable H;
		int i;

		if(tableSize < MinTableSize)
		{
				Error("Table Size Too Small");
				return NULL;
		}

		H = malloc(sizeof(struct HashTbl));
		if(H == NULL)
		{
				FatalError("out of space");
		}

		H->tableSize = NextPrime(tableSize);
		H->theLists = malloc(sizeof(List) * H->tableSize);
		if(H->theLists == NULL)
		{
				FatalError("out of space");
		}

		for(int i=0;i < H->tableSize; ++i)
		{
				H->theLists[i] = malloc(sizeof(struct ListNode));
				if(H->theLists[i] == NULL)
				{
						FatalError("out of space");
				}
				else
				{
						H->theLists[i]->next = NULL;
				}
		}

		return H;
}

Position Find(ElementType key, HashTable H)
{
		Position P;
		List L;

		L = H->theLists[Hash(key,H->tableSize)];
		P = L->next;
		while(P != NULL && P->element != key)
		{
				P=P->next;
		}

		return P;
}

void Insert(ElementType key, HashTable H)
{
		Position pos,newCell;

		List L;

		pos = Find(key,H);
		if(pos == NULL)
		{
				newCell = malloc(sizeof(struct ListNode));
				if(newCell == NULL)
				{
						FatalError("out of space");
				}
				else
				{
						L = H->theLists[Hash(key,H->tableSize)];
						newCell->next = L->next;
						newCell->element = key;
						L->next = newCell;
				}
		}
}

ElementType Retrieve(Position P)
{
		return P->element;
}

void DestroyTable(HashTable H)
{
		int i;
		for(i = 0;i < H->tableSize; ++i)
		{
				Position P = H->theLists[i];
				Position tmp;

				while(P != NULL)
				{
						tmp = P->next;
						free(P);
						P = tmp;
				}
		}
}
