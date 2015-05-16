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
	struct node* x = newNode;

	/* create the right child */
	x->left = ArraytoBST(arr, start, mid - 1);

	/* create the left child */
	x->right = ArraytoBST(arr, mid + 1, end);

	return x;
}

void preorder_print (struct node* x)
{
	if (x == NULL)
	{
		return;
	}
	printf("%d ", x->data);
	preorder_print(x->left);
	preorder_print(x->right);
}

/*
 *	The main function
 */
 int main ()
 {
 	struct node *tree;
 	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
 	int size = sizeof(arr) / sizeof(arr[0]);
 	tree = ArraytoBST(arr, 0, size - 1);
 	printf("Preoder Print:\n");
 	preorder_print(tree);
 	return 0;
 }
