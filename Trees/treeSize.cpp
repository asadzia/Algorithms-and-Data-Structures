/* A program to find the size of the tree i.e the  total nodes in the tree*/

#include <iostream>

using namespace std;

struct node 
{
	node* right;
	node* left;
	int data;
	node(int value) : right(NULL), left(NULL), data(value){}
};

// This can be achieved by post order traversal

int treeSize (node* tree)
{
	if (tree == NULL)
	{
		return 0;
	}
	
	return treeSize(tree->right) + treeSize(tree->left) + 1; 
}

int main()
{
	node* root = new node(1);  //Assigning the Node values
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);	
	cout<<"size of the tree is "<< treeSize(root); //Printing the size of the tree
	return 0;

}
