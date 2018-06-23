#ifndef __REDBLACK_H
#define __REDBLACK_H

typedef int ElementType;
#define NEGINFINITY (-10000)

struct RedBlackNode;
typedef struct RedBlackNode *Position;
typedef struct RedBlackNode *RedBlackTree;

RedBlackTree MakeEmpty(RedBlackTree t);
Position Find(ElementType x,RedBlackTree t);
Position FindMin(RedBlackTree t);
Position FindMax(RedBlackTree t);
RedBlackTree Initialize();
RedBlackTree Insert(ElementType x,RedBlackTree t);
RedBlackTree Remove(ElementType x,RedBlackTree t);
ElementType Retrieve(Position p);
void PrintTree(RedBlackTree t);

#endif
