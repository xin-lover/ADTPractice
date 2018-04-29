#ifndef __AVLTREE_HEADER_
#define __AVLTREE_HEADER_

typedef int ElementType;
struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;

AVLTree MakeEmpty(AVLTree T);
Position Find(ElementType X, AVLTree T);
Position FindMin(AVLTree T);
Position FindMax(AVLTree T);
AVLTree Insert(ElementType X, AVLTree T);
AVLTree Delete(ElementType X, AVLTree T);
ElementType Retrieve(Position P);

#endif
