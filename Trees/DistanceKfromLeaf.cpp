/*
*
* A program to print a the nodes at distance K from the leaf.
*
*
* Created By: Asad Zia
*/

#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

typedef struct node
{
    int data;
    node *left, *right;
} node;

/* utility that allocates a new node with the given key  */
node* newnode(int key)
{
    node* n = new node;
    n->data = key;
    n->left = n->right = NULL;
    return (n);
}

int min (int x, int y)
{
	if (x > y)
	 { 
	 	return y;
	 }
	else 
	 {
	 	return x;
	 }
}

int printNodes (node* x, int n)
{
	int l, r;
	
	/* in case the node is NULL, we return a large number */
	if (x == NULL)
	{
		return INT_MAX; 
	}
	
	/* if there are no childs */
	if (x->left == NULL && x->right == NULL)
	{
		return 1;
	}
	
	/* otherwise recur on the left and right subtrees */
	l = printNodes(x->left, n);
	r = printNodes(x->right, n);
	
	/* a bottom up approach is then used to check if the height is equal to n, then we print the data*/ 
	if (l == n || r == n)
	{
	printf("%d ", x->data);
	}

return (min(l, r) + 1);
}

/* Driver program to test above functions*/
int main()
{
 
    node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->left->right = newnode(8);
 
    cout << "nodes at distance 2 are: ";
    printNodes(root, 2);
 
    return 0;
}
