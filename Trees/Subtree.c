/*
*
* A program to check if a binary tree is a subtree of another tree
*
*
* Created by: Asad zia
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left;
	struct node* right;
	int data;
};

/*
* Initializing the tree structure
*/
struct node* newNode (int y)
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
* A function to check if a subtree is identical to another tree
*/
int checkSub (struct node* T, struct node* S)
{
	if (T == NULL && S == NULL)
	{
		return 1;
	}

	if (T != NULL && S == NULL || T == NULL && S != NULL)
	{
		return 0;
	}

	if (T != NULL && S != NULL)
	{
		if (T->data == S->data)
		{
			return (checkSub(T->right, S->right) && checkSub(T->left, S->left));
		}
	}
}

/*
* A function to check if a tree is a subtree to another tree
*/
int Subtree(struct node* T, struct node* S)
{
	if (S == NULL)
	{
		return 1;
	}

	else if (T == NULL)
	{
		return 0;
	}

	else if (checkSub(T, S) == 1)
	{
		return 1;
	}

	else
	{
		return (Subtree(T->right, S) ||  Subtree(T->left, S));
	}
}

/*
* The main function
*/
int main()
{
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if (Subtree(T, S))
        printf("Tree S is subtree of tree T\n");
    else
        printf("Tree S is not a subtree of tree T\n");
 
    return 0;
}

/*
Another approach:

bool checkSub (node* root, node* sub)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data > sub->data)
    {
        checkSub(root->left, sub);
    }
    else if (root->data < sub->data)
    {
        checkSub(root->right, sub);
    }
    else
    {
        checkSub(root->right, sub->right);
        checkSub(root->left, sub->left);
    }

    return true;
}

bool isSubtree (node* root, node* sub)
{
    if (root == NULL && sub == NULL)
    {
        return true;
    }

    else if (root == NULL && sub != NULL)
    {
        return false;
    }

    else if (root != NULL && sub == NULL)
    {
        return true;
    }
    else
    {
        return checkSub (root, sub);
    }
}

*/
