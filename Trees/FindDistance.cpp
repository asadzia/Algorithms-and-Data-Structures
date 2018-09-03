/*  A program to create a binary search tree from a list of integers without rebalancing the tree and adding the integers
as they are in the array and then finding the distance between two nodes in the BST by counting the number of edges between them */

#include <iostream>
#include <vector>

using namespace std;

struct node
{
	struct node* left;
	struct node* right;
	int data;
	node(struct node* l, struct node* r, int value):left(l),right(r),data(value){};
};

struct node* newNode (int data)
{
	return new node(NULL, NULL, data);
}

struct node* insert (struct node* tree, int data)
{
	if (tree == NULL)
	{
		return newNode(data);
	}
	else if (data > tree->data)
	{
		tree->right = insert(tree->right, data);
	}
	else if (data < tree->data)
	{
		tree->left = insert(tree->left, data);
	}
	return tree;
}

struct node* findLowestCommonAncestor (struct node* tree, int n1, int n2)
{
	if (tree == NULL)
	{
		return NULL;
	}
	
	else if (tree->data > n1 && tree->data > n2)
	{
		tree = findLowestCommonAncestor(tree->left, n1, n2);
	}
	
	else if (tree->data < n1 && tree->data < n2)
	{
		tree = findLowestCommonAncestor(tree->right, n1, n2);
	}
	return tree;
}

int findNodeAndCountEdges (struct node* tree, int n)
{
	int countEdges = 0;

	if (tree == NULL)
	{
		return -999999999;
	}	
	else if (tree->data == n)
	{
		return 0;
	}
	else if (tree->data > n)
	{
		countEdges += findNodeAndCountEdges(tree->left, n) + 1;
	}
	else if (tree->data < n)
	{
		countEdges += findNodeAndCountEdges(tree->right, n) + 1;
	}
	return countEdges;
}

int findDistance (struct node* tree, int n1, int n2)
{
	node* lcm = findLowestCommonAncestor(tree, n1, n2);

	int distance = findNodeAndCountEdges(lcm, n1) + findNodeAndCountEdges(lcm, n2);

	if (distance < 0)
	{
		return -1;
	}
	else
	{
		return distance;
	}
}

struct node* createBST (vector<int> values, int size)
{
	struct node* tree = NULL;

	// Create BST
	for (int i = 0; i < size; ++i)
	{
		tree = insert(tree, values[i]);
	}

  return tree;
}

void printInorder (struct node* tree)
{
	if (tree == NULL)
	{
		return;
	}
	printInorder(tree->left);
	cout << tree->data << endl;
	printInorder(tree->right);
}

int Result (vector<int> values, int size, int n1, int n2)
{
	node* tree = createBST(values, size);
	return findDistance(tree, n1, n2);
}

int main ()
{
  /* Test 1 */
	//vector<int> values {5,6, 3, 1, 2, 4};
	//int n = 6;
	//int n1 = 2, n2 = 4;

  /* Test 2 */
  vector<int> values {9, 7, 5, 3, 1};
	int n = 5;
	int n1 = 7, n2 = 20;


  //node* tree = createBST(values, n);
  //printInorder(tree);
  //node* _tree = findLowestCommonAncestor(tree, n1, n2);
  //cout << "LCM: " << _tree->data << endl;

	cout << "Distance: " << Result(values, n, n1, n2) << endl;

	return 0;
}
