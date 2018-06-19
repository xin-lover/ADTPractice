#ifndef _LEFTHEAP_H
#define _LEFTHEAP_H

typedef int ElementType;

struct TreeNode;
typedef struct TreeNode *PriorityQueue;

PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

#define Insert(x,H) (H = Insert1((x),H))
#define DeleteMin(H) ({ElementType ret = FindMin(H);H = DeleteMin1(H);ret;})

PriorityQueue Insert1(ElementType x, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

#endif
