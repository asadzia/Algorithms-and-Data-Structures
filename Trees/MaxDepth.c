/*
* A program to find the maximum depth of a tree in C.
*
*
* Created by: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	struct node* left;
	struct node* right;
	int data;
};

/*
* Initializing the tree structure
*/
struct node* init (int y)
{
	struct node* x;
	x = (struct node*)malloc(sizeof(struct node));
	if (x == NULL)
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}

	x->right = x->left = NULL;
	x->data = y;
	return x;
}

/*
* A function to find the maximum depth
*/
int maxDepth (struct node* x)
{
	if (x == NULL)
	{
		return 0;
	}

	int left = maxDepth(x->left);
	int right = maxDepth(x->right);

	if (left > right)
	{
		return (left + 1);
	}
	else
	{
		return (right + 1);
	}
}

/*
* The main function
*/
int main ()
{
	struct node* y = NULL;
	struct node* z = NULL;
	struct node* p = NULL;
	struct node* q = NULL;
	struct node* r = NULL;
	struct node* l = NULL;
	struct node* m = NULL;
	struct node* n = NULL;
	y = init(2);
	z = init(3);
	p = init(4);
	q = init(5);
	r = init(6);
	l = init(7);
	m = init(8);
	n = init(9);

	p->right = n;
	n->left = m;
	m->left = r;
	r->right = l;
	r->left = q;
	p->left = z;
	z->left = y;

	int result = maxDepth(p);
	printf("Maximum depth: %d\n", result);
	return 0;
}
