/*
*
* A program to convert a sorted array to a binary tree in C.
*
* Created by Asad Zia.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* right;
	struct node* left;
};

/*
 *	The function for converting an array to a binary search tree
 */
struct node* ArraytoBST (int arr[], int start, int end)
{
	if (start > end)
	{
		return NULL;
	}

	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL)
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}

	newNode->right = newNode->left = NULL;
	
	/* create the root/parent */
	int mid = (start + end) / 2;
	newNode->data = arr[mid];
	x = newNode;

	/* create the right child */
	x->left = ArraytoBST(arr, start, mid - 1);

	/* create the left child */
	x->right = ArraytoBST(arr, mid + 1, end);

	return x;
}

void inorder_print (struct node* x)
{
	if (x == NULL)
	{
		return;
	}

	inorder_print(x->left);
	printf("%d ", x->data);
	inorder_print(x->right);
}

/*
 *	The main function
 */
 int main ()
 {
 	struct node *tree;
 	int arr[] = {5, 2, 7, 9, 1, 4, 7, 2};
 	int size = sizeof(arr) / sizeof(arr[0]);
 	tree = ArraytoBST(arr, 0, size - 1);
 	inorder_print(tree);
 	return 0;
 }
