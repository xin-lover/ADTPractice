#ifndef __TREAP_H
#define __TREAP_H

#define Infinity RAND_MAX

typedef int ElementType;
struct TreapNode;
typedef struct TreapNode *Position;
typedef struct TreapNode *Treap;

Treap MakeEmpty(Treap t);
Position Find(ElementType x, Treap t);
Position FindMin(Treap t);
Position FindMax(Treap t);
Treap Initialize();
Treap Insert(ElementType x, Treap t);
Treap Remove(ElementType x, Treap t);
ElementType Retrieve(Position p);
void PrintTree(Treap p);

extern Position NullNode;
#endif
