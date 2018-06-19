#include "../hashsep.h"
#include <assert.h>

int main()
{
		HashTable table = InitializeTable(30);
		Insert(2,table);
		Insert(20,table);
		Insert(80,table);

		Position p = Find(20,table);
		assert(Retrieve(p) == 20);
		printf("%d\n",Retrieve(Find(80,table)));
		return 0;
}
