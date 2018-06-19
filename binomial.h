#ifndef _BINOMIAL_H
#define _BINOMIAL_H

typedef long ElementType;
#define Infinity 30000L

#define MAXTREES 14
#define CAPACITY 16383

struct BinNode;
typedef struct BinNode *BinTree;
struct Collection;
typedef struct Collection *BinQueue;

BinQueue Initialize();
void Destroy(BinQueue H);
BinQueue MakeEmpty(BinQueue H);
BinQueue Insert(ElementType x, BinQueue H);
ElementType DeleteMin(BinQueue H);
BinQueue Merge(BinQueue H1,BinQueue H2);
ElementType FindMin(BinQueue H);
int IsEmpty(BinQueue H);
int IsFull(BinQueue H);


#endif
