#ifndef __SKIPLIST_H
#define __SKIPLIST_H

typedef int ElementType;
#define Infinity (10000)

struct SkipNode;
typedef struct SkipNode *Position;
typedef struct SkipNode *SkipList;

SkipList MakeEmpty(SkipList L);
Position Find(ElementType x, SkipList L);
Position FindMin(SkipList L);
Position FindMax(SkipList L);
SkipList Initialize();
SkipList Insert(ElementType x,SkipList L);
SkipList Remove(ElementType x,SkipList L);
ElementType Retrieve(Position P);
#endif
