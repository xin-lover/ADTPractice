#ifndef __SORT_H
#define __SORT_H

#include <stdlib.h>
#include <math.h>
#include "fatal.h"

typedef int ElementType;

void InsertSort(ElementType a[],int n)
{
	int i;
	int j;
	for(i=1;i < n; ++i)
	{
			ElementType tmp = a[i];
			for(j = i-1; j >=0 && a[j] > tmp; --j)
			{
					a[j+1] = a[j];
			}
			a[j + 1] = tmp;
	}
}

void ShellSort(ElementType a[], int n)
{
		int i;
		int j;
		int increment;

		ElementType tmp;
		for(increment = n / 2; increment > 0; increment /=2)
		{
				for(i= increment; i < n; ++i)
				{
						tmp = a[i];
						for(j=i; j >= increment && a[j - increment] > tmp;j-=increment)
						{
								a[j] = a[j -increment];
						}

						a[j] = tmp;
				}
		}
}

static int GetShellIncrement9(int i)
{
		return 9 * pow(4,i) - 9 * pow(2,i) + 1;
}

static int GetShellIncrement4(int i)
{
		return pow(4,i) - 3 * pow(2,i) + 1;
}

void GetShellIncrement(int array[],int n)
{
	if(array == NULL)
	{
			return;
	}

	int j = 0;
	int i=0;
	while(1)
	{
		int c1 = GetShellIncrement4(i);
		int c2 = GetShellIncrement9(i);

		int c = (c1 > 0 && c1 < c2) ? c1 : c2;

		if(c1 > 0)
		{
				array[j++] = c1;
		}

		array[j++] = c2;
		if(j >= n)
		{
				break;
		}

		++i;
	}

	InsertSort(array,n);
}

#define leftChild(i) (2 * (i) + 1)

void PerDown(ElementType a[],int i, int n)
{
		int child;
		ElementType tmp = a[i];
		for(;;)
		{
				child = leftChild(i);
				if(child >= n)
				{
						break;
				}
				if(child + 1 < n)
				{
						if(a[child] < a[child + 1])
						{
								child++;
						}
						
				}

				if(a[child] > tmp)
				{
						a[i] = a[child];
				}
				else
				{
						break;
				}

				i=child;

		}

		a[i] = tmp;

}


static void Swap(ElementType *a, ElementType *b)
{
		ElementType tmp = *a;
		*a = *b;
		*b = tmp;
}

void HeapSort(ElementType a[], int n)
{
		//build heap
		int i;
		for( i = n / 2; i >= 0; i-- )
		{
			PerDown(a,i,n);
		}

		for(i = n - 1; i >0;i--)
		{
			Swap(&a[0],&a[i]);/*delete max*/
			PerDown(a,0,i);
		}
}

void Merge(ElementType a[], ElementType tmpA[],int lpos,int rpos,int rightEnd)
{
		int i;
		int leftEnd;
		int numElements;
		int tmpPos;

		leftEnd = rpos - 1;
		tmpPos = lpos;
		numElements = rightEnd - lpos + 1;

		while(lpos <= leftEnd && rpos <= rightEnd)
		{
				if(a[lpos] <= a[rpos])
				{
						tmpA[tmpPos++] = a[lpos++];
				}
				else
				{
						tmpA[tmpPos++] = a[rpos++];
				}
		}

		/*copy rest of left*/
		while(lpos <= leftEnd)
		{
				tmpA[tmpPos++] = a[lpos++];
		}

		/*copy rest of right*/
		while(rpos <= rightEnd)
		{
				tmpA[tmpPos++] = a[rpos++];
		}

		/*copy elements back*/
		for(i = 0; i < numElements;i++,rightEnd--)
		{
				a[rightEnd] = tmpA[rightEnd];
		}
}

void MSort(ElementType a[],ElementType tmpA[],int left,int right)
{
		int center;
		if(left < right)
		{
				center = (left + right) / 2;
				MSort(a,tmpA,left,center);
				MSort(a,tmpA,center+1,right);
				Merge(a,tmpA,left,center+1,right);
		}
}

void MergeSort(ElementType a[], int n)
{
		ElementType *tmpA;
		tmpA = (ElementType*)malloc(n * sizeof(ElementType));
		if(tmpA == NULL)
		{
				FatalError("out of space");
		}
		else
		{
				MSort(a,tmpA,0,n-1);
				free(tmpA);
		}
}

ElementType Median3(ElementType a[], int left, int right)
{
		int center = (left + right) / 2;
		if(a[left] > a[center])
		{
				Swap(&a[left],&a[center]);
		}

		if(a[left] > a[right])
		{
				Swap(&a[left],&a[right]);
		}

		if(a[center] > a[right])
		{
				Swap(&a[center],&a[right]);
		}

		Swap(&a[center],&a[right-1]);
		return a[right - 1];
}

#define Cutoff (3)

void QSort(ElementType a[],int left, int right)
{
		int i;
		int j;

		ElementType pivot;
		if(left + Cutoff <= right)
		{
				pivot = Median3(a,left,right);
				i=left;
				j = right -1;
				for(;;)
				{
						while(a[++i] < pivot){}
						while(a[--j] > pivot){}

						if(i < j)
						{
							Swap(&a[i],&a[j]);
						}
						else
						{
								break;
						}
				}

				Swap(&a[i],&a[right-1]);

				QSort(a,left,i-1);
				QSort(a,i+1,right);
		}
		else
		{
				InsertSort(a+left,right - left +1);
		}
}

void QuikSort(ElementType a[], int n)
{
		QSort(a,0,n-1);
}



#endif
