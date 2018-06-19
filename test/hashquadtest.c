#include "../hashquad.h"
#include <stdio.h>
#include <assert.h>

int main()
{
		HashTable table;
		table = InitializeTable(30);
		Insert(2,table);
		Insert(3, table);
		Insert(20,table);

		assert(Retrieve(Find(20,table),table)== 20);
		printf("%d\n",Retrieve(Find(20,table),table));
		DestroyTable(table);
		return 0;
}
