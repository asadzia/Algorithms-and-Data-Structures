/* A program to delete an entire tree */

#include <iostream>

struct node 
{
	node* right;
	node* left;
	int data;
	node(int value) : right(NULL), left(NULL), data(value){}
};

// This can be achieved by post order traversal

void deleteTree (node* tree)
{
	if (tree == NULL)
	{
		return;
	}

	deleteTree(tree->left);
	deleteTree(tree->right);
	delete tree;
}
