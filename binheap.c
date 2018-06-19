#include "binheap.h"
#include "fatal.h"

#include <stdlib.h>

#define MINPQCAPACITY 10
#define MINDATA -32767

struct HeapStruct
{
		int capacity;
		int size;
		ElementType *elements;
};

PriorityQueue Initialize(int maxElements)
{
	PriorityQueue H;
	if(maxElements < MINPQCAPACITY)
	{
		Error("too small capacity.");
		return NULL;
	}

	H = malloc(sizeof(struct HeapStruct));
	if(H == NULL)
	{
			FatalError("out of space");
	}

	H->elements = malloc(sizeof(ElementType) * (maxElements + 1));
	if(H->elements == NULL)
	{
			FatalError("out of space");
	}

	H->capacity = maxElements;
	H->size = 0;
	H->elements[0] = MINDATA;

	return H;
}

void Insert(ElementType x, PriorityQueue H)
{
		if(H == NULL)
		{
				Error("Insert To NULL");
				return;
		}

		if(IsFull(H))
		{
				Error("Priority queue is full");
				return;
		}
		int i;

		/*H->size += 1;
		H->elements[H->size] = x;

		do
		{
				i = H->size / 2;
				if(H->elements[H->size]< H->elements[i])
				{
						int tmp = H->elements[H->size];
						H->elements[H->size] = H->elements[i];
						H->elements[i] = tmp;
				}
				else
				{
						break;
				}

		}while(i > 0);*/

		for(i = ++H->size; H->elements[i / 2] > x; i /= 2)
		{
				H->elements[i] = H->elements[ i / 2 ];
		}
		H->elements[i] = x;
}

ElementType DeleteMin(PriorityQueue H)
{
		int i;
		int child;

		if(IsEmpty(H))
		{
				Error("Priority queue is empty");
				return H->elements[0];
		}

		ElementType min;
		ElementType last;
		min = H->elements[1];
		last = H->elements[H->size--];
		for( i = 1; i * 2 <= H->size; i= child )
		{
				child = i * 2;
				if(child != H->size && H->elements[child + 1] < H->elements[child])
				{
						child ++;
				}

				if(last > H->elements[child])
				{
						H->elements[i] = H->elements[child];
				}
				else
				{
						break;
				}
		}

		H->elements[i] = last;
		return min;
}

ElementType FindMin(PriorityQueue H)
{
		if(IsEmpty(H))
		{
				Error("Priority is Empty");
				return H->elements[0];
		}
		return H->elements[1];
}

void MakeEmpty(PriorityQueue H)
{
		H->size = 0;
}

int IsEmpty(PriorityQueue H)
{
		return H->size == 0;
}

int IsFull(PriorityQueue H)
{
		return H->size == H->capacity;
}

void Destroy(PriorityQueue H)
{
		if(H != NULL)
		{
				free(H->elements);
				free(H);
		}
}
