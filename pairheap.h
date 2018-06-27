#ifndef __PAIRHEAP_H
#define __PAIRHEAP_H

typedef int ElementType;

struct PairNode;
typedef struct PairNode *PairHeap;
typedef struct PairNode *Position;

PairHeap Initialize();
void Destroy();
PairHeap MakeEmpty(PairHeap H);
PairHeap Insert(ElementType item,PairHeap H,Position *loc);
PairHeap DeleteMin(ElementType *minItem,PairHeap H);
ElementType FindMin(PairHeap H);
PairHeap DecreaseKey(Position p,ElementType newVal,PairHeap H);
int IsEmpty(PairHeap H);
int IsFull(PairHeap H);

#endif
