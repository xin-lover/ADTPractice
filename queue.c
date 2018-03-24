#include "queue.h"
#include "fatal.h"
#include <stddef.h>

#define MIN_QUEUE_SIZE 5

struct QueueRecord
{
	int capacity;
	int front;
	int rear;
	int size;
	ElementType *array;
};

int IsEmpty(Queue Q)
{
		return Q->size == 0;
}

int IsFull(Queue Q)
{
		return Q->size == Q->capacity;
}

Queue CreateQueue(int maxElements)
{
		Queue Q;
		if(maxElements < MIN_QUEUE_SIZE)
		{
			Error("Queue size is too small\n");			
		}
		Q = (Queue)malloc(sizeof(struct QueueRecord));
		if(Q == NULL)
		{
				FatalError("out of memory\n");
		}
		Q->capacity = maxElements;
		Q->rear = 0;
		Q->front = 1;
		Q->size = 0;
		Q->array = (ElementType*)malloc(sizeof(ElementType) * maxElements);
		if(Q->array == NULL)
		{
				FatalError("out of memory\n");
		}

		return Q;
}

void DisposeDeueue(Queue Q)
{
	if(Q != NULL)
	{
			free(Q->array);
			free(Q);
	}
}

void MakeEmpty(Queue Q)
{
		if(Q == NULL)
		{
				return;
		}
		Q->size = 0;
		Q->rear = 0;
		Q->front = 1;
}

void Enqueue(ElementType X,Queue Q)
{
		if(IsFull(Q))
		{
				Error("Full queue\n");
				return ;
		}
		Q->size++;
		Q->rear+=1;
		if(Q->rear >= Q->capacity)
		{
				Q->rear = 0;
		}
		Q->array[Q->rear] = X;
}

ElementType Front(Queue Q)
{
		if(Q == NULL)
		{
				Error("NULL reference\n");
				return 0;
		}
		if(IsEmpty(Q))
		{
				Error("Empty queue\n");
				return 0;
		}
		return Q->array[Q->front];
}

void Dequeue(Queue Q)
{
		if(IsEmpty(Q))
		{
				return;
		}
		Q->front +=1;
		if(Q->front >= Q->capacity)
		{
				Q->front = 0;
		}
		Q->size -=1;
}

ElementType FrontAndDequeue(Queue Q)
{
		ElementType t = 0;
		if(!IsEmpty(Q))
		{
				t = Front(Q);
		}
		Dequeue(Q);
		return t;
}
