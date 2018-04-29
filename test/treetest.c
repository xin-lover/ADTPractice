#include <stdio.h>
#include "../tree.h"

struct TreeNode
{
		ElementType element;
		SearchTree left;
		SearchTree right;
};

void PrintTree(SearchTree T)
{
		printf("%d\n",T->element);
		if(T->right != NULL)
		{
				PrintTree(T->right);
		}
		if(T->left != NULL)
		{
				PrintTree(T->left);
		}
}
int main()
{
		SearchTree tree = NULL;
		tree = Insert(8,tree);
		tree = Insert(2,tree);
		tree = Insert(6,tree);
		tree = Insert(1,tree);
		Position temp = tree;
		PrintTree(temp);
		Position aa = FindMax(tree);
		printf("%d\n",aa->element);
		return 0;
}
