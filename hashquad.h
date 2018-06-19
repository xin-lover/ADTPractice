#ifndef __HASHQUAD_H
#define __HASHQUAD_H

typedef int ElementType;

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int tableSize);
void DestroyTable(HashTable H);
Position Find(ElementType key, HashTable H);
void Insert(ElementType key,HashTable H);
ElementType Retrieve(Position P,HashTable H);
HashTable ReHash(HashTable H);

#endif
