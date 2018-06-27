#ifndef __KDTREE_H
#define __KDTREE_H

typedef int ElementType;
typedef ElementType ItemType[2];

struct KdNode;
typedef struct KdNode *Position;
typedef struct KdNode *KdTree;

KdTree Insert(ItemType item,KdTree t);
void PrintRange(ItemType low, ItemType high, KdTree t);

#endif
