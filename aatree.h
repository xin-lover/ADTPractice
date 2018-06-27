#ifndef __AATREE_H
#define __AATREE_H

typedef int ElementType;

struct AANode;
typedef struct AANode *Position;
typedef struct AANode *AATree;

AATree MakeEmpty(AATree T);
Position Find(ElementType x, AATree t);
Position FindMin(AATree t);
Position FindMax(AATree t);
AATree Initialize();
AATree Insert(ElementType x, AATree t);
AATree Remove(ElementType x, AATree t);
ElementType Retrieve(Position P);
void PrintTree(AATree t);

extern Position NullNode;

#endif
