#include "aatree.h"
#include "fatal.h"

Position NullNode = NULL;

struct AANode
{
		ElementType element;
		AATree left;
		AATree right;
		int level;
};

AATree Initialize()
{
		if(NullNode == NULL)
		{
				NullNode = malloc(sizeof(struct AANode));
				if(NullNode == NULL)
				{
						FatalError("out of space");
				}

				NullNode->left = NullNode->right = NullNode;
				NullNode->level = 0;
		}

		return NullNode;
}

AATree MakeEmpty(AATree t)
{
		if(t != NullNode)
		{
				MakeEmpty(t->left);
				MakeEmpty(t->right);
				free(t);
		}

		return NullNode;
}

Position Find(ElementType x, AATree t)
{
		if(t == NullNode)
		{
				return NullNode;
		}

		if(x < t->element)
		{
				return Find(x,t->left);
		}
		else if(x > t->element)
		{
				return Find(x,t->right);
		}
		else
		{
				return t;
		}
}

Position FindMin(AATree t)
{
		if(t == NullNode)
		{
				return NullNode;
		}
		else
		if(t->left == NullNode)
		{
				return t;
		}
		else
		{
				return FindMin(t->left);
		}
}

Position FindMax(AATree t)
{
		if(t != NullNode)
		{
				while(t->right != NullNode)
				{
						t=t->right;
				}
		}

		return t;
}

static Position SingleRotateWithLeft(Position K2)
{
		Position K1;

		K1 = K2->left;
		K2->left = K1->right;
		K1->right = K2;

		return K1;
}

static Position SingleRotateWithRight(Position K1)
{
		Position K2;

		K2 = K1->right;
		K1->right = K2->left;
		K2->left = K1;

		return K2;
}

AATree Skew(AATree t)
{
		if(t->left->level == t->level)
		{
				printf("skew %d\n",t->element);
				t = SingleRotateWithLeft(t);
		}

		return t;

}

AATree Split(AATree t)
{
		if(t->right->right->level == t->level)
		{
				printf("split %d\n",t->element);
				t = SingleRotateWithRight(t);
				t->level++;
		}

		return t;
}

AATree Insert(ElementType item, AATree t)
{
	if(t == NullNode)
	{
			t = malloc(sizeof(struct AANode));
			if(t == NULL)
			{
					FatalError("out of space");
			}
			else
			{
					t->element = item;
					t->level = 1;
					t->left = t->right = NullNode;
			}
	}
	else if(item < t->element)
	{
			t->left = Insert(item,t->left);
	}
	else if(item > t->element)
	{
			t->right = Insert(item,t->right);
	}

	t = Skew(t);
	t = Split(t);
	return t;
}

AATree Remove(ElementType item, AATree t)
{
		static Position deletePtr, lastPtr;
		if(t != NullNode)
		{
				lastPtr = t;
				printf("ia %d\n",lastPtr->element);
				if(item < t->element)
				{
						printf("ib %d\n",t->left->element);
						t->left = Remove(item,t->left);
				}
				else
				{
						deletePtr = t;
						printf("ic %d %d\n",deletePtr->element,t->right->element);
						t->right = Remove(item,t->right);
				}

				printf("if %d %d\n",t->element,lastPtr->element);
				if(t == lastPtr)
				{
						printf("ig\n");
						if(deletePtr != NullNode &&
										item == deletePtr->element)
						{
								printf("id %d\n",deletePtr->element);
								deletePtr->element = t->element;
								deletePtr = NullNode;
								t = t->right;
								free(lastPtr);
						}
				}
				else if(t->left->level < t->level - 1 ||
								t->right->level < t->level - 1)
				{
						printf("ie %d %d %d %d\n",t->element,t->level,t->left->level,t->right->level);
					if(t->right->level > --t->level)
					{
							printf("adfd");
							t->right->level = t->level;
					}

					t=Skew(t);
					printf("nb1\n");
					t->right = Skew(t->right);
					printf("nb2\n");
					t->right->right = Skew(t->right->right);
					t = Split(t);
					t->right = Split(t->right);
				}
		}

		return t;
}

ElementType Retrieve(Position p)
{
		return p->element;
}

void PrintTree(AATree t)
{
		if(t != NullNode)
		{
				printf("%d %d\n",t->element,t->level);
				printf("left ");
				PrintTree(t->left);
				printf("\n right ");
				PrintTree(t->right);
				printf("\n");

		}
}
