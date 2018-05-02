#ifndef __SPLAYTREE_HEADER__
#define __SPLAYTREE_HEADER__

typedef int ElementType;

struct SplayNode;
typedef struct SplayNode *SplayTree;

SplayTree MakeEmpty(SplayTree T);
SplayTree Find(ElementType X, SplayTree T);
SplayTree FindMin(SplayTree T);
SplayTree FindMax(SplayTree T);
SplayTree Initialize(void);
SplayTree Insert(ElementType X, SplayTree T);
SplayTree Remove(ElementType X, SplayTree T);
ElementType Retrieve(SplayTree T);

#endif
