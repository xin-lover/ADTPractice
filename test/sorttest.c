#include <stdio.h>
#include "../sort.h"

int main()
{
		int ia[] = {2,3,1,0,5,4};
		//InsertSort(ia,6);
		//ShellSort(ia,6);
		//HeapSort(ia,6);
		//MergeSort(ia,6);
		QuikSort(ia,6);
		for(int i=0;i < 6;++i)
		{
				printf("%d ",ia[i]);
		}
		printf("\n");

		return 0;
}
