#include "stack.h"
#include "fatal.h"
#include <stddef.h>

#define EMPTY_TOP -1
#define MIN_STACK_SIZE 5

struct StackRecord
{
	int capacity;
	int topOfStack;
	ElementType *array;
};

int IsEmpty(Stack S)
{
		return S->topOfStack <= EMPTY_TOP; 
}

int IsFull(Stack S)
{
		return S->topOfStack >= S->capacity -1;
}

Stack CreateStack(int maxElements)
{
		Stack s = NULL;
		if(maxElements < MIN_STACK_SIZE)
		{
				Error("Stack size is too small.\n");
		}
		s = (Stack)malloc(sizeof(struct StackRecord));
		if(s == NULL)
		{
				FatalError("out of memory\n");
		}
		s->capacity = maxElements;
		s->array = (ElementType*)malloc(sizeof(ElementType) * maxElements);
		if(s->array == NULL)
		{
				FatalError("out of memory\n");
		}

		s->topOfStack = EMPTY_TOP;
		return s;
}

void DisposeStack(Stack S)
{
		if(S != NULL)
		{
				free(S->array);
				free(S);
				S = NULL;
		}
}

void MakeEmpty(Stack S)
{
		if(S != NULL)
		{
				S->topOfStack = EMPTY_TOP;;
		}
}

void Push(ElementType X, Stack S)
{
		if(!IsFull(S))
		{
				S->array[++S->topOfStack] = X;
		}
		else
		{
				Error("full Stack.\n");
		}
}

ElementType Top(Stack S)
{
		if(IsEmpty(S))
		{
				Error("Empty Stack.\n");
				return 0;
		}
		return S->array[S->topOfStack];
}

void Pop(Stack S)
{
		if(!IsEmpty(S))
		{
				S->topOfStack--;
		}
		else
		{
				Error("Empty Stack.\n");
		}
}

ElementType TopAndPop(Stack S)
{
		if(IsEmpty(S))
		{
				Error("Empty Stack.\n");
				return 0;
		}
		return S->array[S->topOfStack--];
}
