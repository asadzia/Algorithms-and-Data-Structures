/* A program to compae of two trees are identical */

#include <iostream>

struct node 
{
	node* right;
	node* left;
	int data;
	node(int value) : right(NULL), left(NULL), data(value){}
};

bool compareTrees (node* tree1, node* tree2)
{
	if (tree1 == NULL && tree2 == NULL)
	{
		return true;
	}

	if (tree1 != NULL && tree2 != NULL)
	{
		if (tree1->data == tree2->data)
		{
			return compareTrees(tree1->right, tree2->right) && compareTrees(tree1->left, tree2->left);
		}
	}

	return false;
}
