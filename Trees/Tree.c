/*
*
* A Binary tree implementation in C
* 
* Created By: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* initialize (int y)
{	
	struct node* x;
	x = (struct node* )malloc(sizeof(struct node));
	if (x == NULL) 
	{
		printf("Error in memory allocation\n");
		exit(1);
	}
	x->right = NULL;
	x->left = NULL;
	x->data = y;
	return x;
}

struct node* insert (struct node* x, int y) 
{
	if (x == NULL)
	{
		x = initialize(y);
	}

	else if (x->data < y)
	{
		x->right = insert(x->right, y);
	}
	else if (x->data > y)
	{
		x->left = insert(x->left, y);
	}
	return x;
} 

/*
* If a node is present return 0 for true else return 1 for false
*/
int search (struct node* x, int y)
{
	if (x == NULL)
	{
		return 1;
	}
	else if (x->data == y)
	{
		return 0;
	}
	else if (x->data > y)
	{
		return search(x->left, y);
	}
	else
	{
		return search(x->right, y);
	}
}

void inorder (struct node* x) 
{
	if (x == NULL)
	{
		return;
	}
	inorder(x->left);
	printf("%d ", x->data);
	inorder(x->right);
}

void postorder (struct node* x)
{
	if (x == NULL)
	{
		return;
	}
	postorder(x->left);
	postorder(x->right);
	printf("%d ", x->data);
}

void preorder (struct node* x) 
{
	if (x == NULL)
	{
		return;
	}
	printf("%d ", x->data);
	preorder(x->left);
	preorder(x->right);
}

struct node* getMin (struct node* x)
{
	struct node* current = x;

	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

struct node* deleteNode (struct node* x, int y)
{
	struct node* temp;

	if (x == NULL)
	{
		return x;
	}

	if (x->data > y)
	{
		x->left = deleteNode(x->left, y);
	}
	else if (x->data < y)
	{
		x->right = deleteNode(x->right, y);
	}
	else
	{
		/* the condition with no child */
		if (x->left == NULL && x->right == NULL)
		{
			free(x);
		}
		/* the condition with only one child */
		else if (x->left == NULL)
		{
			temp = x->right;
			free(x);
			return temp;
		}
		else if (x->right == NULL)
		{
			temp = x->left;
			free(x);
			return temp;
		}
		/* the condition with two childs */
		else
		{
			temp = getMin(x->right);
			x->data = temp->data;
			x->right = deleteNode(x->right, temp->data);
		}
	}
	return x;
}

/*
* the main function
*/

int main ()
{
	struct node* tree = NULL;
	tree = insert(tree, 0);
	tree = insert(tree, 1);
	tree = insert(tree, 2);
	tree = insert(tree, 4);
	tree = insert(tree, 5);
	tree = insert(tree, 3);
	tree = insert(tree, 6);
	tree = insert(tree, 8);
	tree = insert(tree, 9);
	tree = insert(tree, 10);

	printf("Inorder\n");
	inorder(tree);
	printf("\nPreorder\n");
	preorder(tree);
	printf("\nPostorder\n");
	postorder(tree);

	tree = deleteNode(tree, 2);
	printf("\nInorder\n");
	inorder(tree);
	
	return 0;
}
