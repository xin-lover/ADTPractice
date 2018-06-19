#ifndef _HASHSEP_H
#define _HASHSEP_H

typedef int ElementType;
typedef unsigned int Index;

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int tableSize);
void DestroyTable(HashTable H);
Position Find(ElementType key, HashTable H);
void Insert(ElementType key,HashTable H);
ElementType Retrieve(Position P);

#endif
