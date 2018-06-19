#include "hashquad.h"
#include "fatal.h"

#include <stdlib.h>

#define MinTableSize (10)

enum KindOfEntry { Legitimate, Empty,Deleted };

struct HashEntry
{
		ElementType element;
		enum KindOfEntry info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
		int tableSize;
		Cell *theCells;
};

static int  NextPrime(int n)
{
		int i;

		if(n % 2 == 0)
		{
				n++;
		}

		for(;; n+=2)
		{
				for(i = 3; i * i <= n; i+=2)
				{
						if(n % i == 0)
						{
								goto ContOuter;
						}
				}

				return n;
ContOuter:;
		}
}

Index Hash(ElementType key, int tableSize)
{
		return key % tableSize;
}

HashTable InitializeTable(int tableSize)
{
		if(tableSize < MinTableSize)
		{
				Error("Table size too small.");
				return NULL;
		}

		HashTable H;
		int i;
		H = malloc(sizeof(struct HashTbl));
		if(H == NULL)
		{
				FatalError("out of space");
		}

		H->tableSize = NextPrime(tableSize);

		H->theCells = malloc(sizeof(Cell) * H->tableSize);
		if(H->theCells == NULL)
		{
				FatalError("out of space");
		}
		for(i = 0;i < H->tableSize; ++i)
		{
			H->theCells[i].info = Empty;
		}

		return H;
}

Position Find(ElementType key, HashTable H)
{
		Position currentPos;
		int collisionNum;

		collisionNum = 0;
		currentPos = Hash(key,H->tableSize);
		while(H->theCells[currentPos].info != Empty &&
						H->theCells[currentPos].element != key)
		{
				currentPos += 2 * ++collisionNum - 1;
				if(currentPos >= H->tableSize)
				{
						currentPos -= H->tableSize;
				}
		}

		return currentPos;
}

void Insert(ElementType key,HashTable H)
{
		Position pos;

		pos = Find(key,H);
		if(H->theCells[pos].info != Legitimate)
		{
				H->theCells[pos].info = Legitimate;
				H->theCells[pos].element = key;
		}
}

HashTable ReHash(HashTable H)
{
		int i;
		int oldSize;
		Cell *oldCells;

		oldCells = H->theCells;
		oldSize = H->tableSize;

		H = InitializeTable(2 * oldSize);
		for(i = 0;i < oldSize;i++)
		{
				if(oldCells[i].info == Legitimate)
				{
						Insert(oldCells[i].element,H);
				}
		}

		free(oldCells);

		return H;
}

ElementType Retrieve(Position p, HashTable H)
{
		return H->theCells[p].element;
}

void DestroyTable(HashTable H)
{
		free(H->theCells);
		free(H);
}
