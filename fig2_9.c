#include <stdio.h>

typedef int ElementType;
#define NotFound (-1)

int BinarySearch(const ElementType a[],ElementType x, int n)
{
		int low;
		int mid;
		int high;

		low = 0;
		high = n- 1;
		while( low < high )
		{
				mid = (low + high) / 2;
				if(a[mid] < x)
				{
						low = mid + 1;
				}
				else if(a[mid] > x)
				{
						high = mid - 1;
				}
				else
				{
						return mid;
				}
		}

		return NotFound;
}

int main()
{
		static int a[] = {1,3,4,5,6,7,9,13,15,17,19};
		const int sizeofa = sizeof(a) / sizeof(int);

		int i;
		for(i = 0;i < 20; i++)
		{
				printf("BinarySearch of %d returns %d\n",
								i,BinarySearch(a,i,sizeofa));
		}

		return 0;
}
