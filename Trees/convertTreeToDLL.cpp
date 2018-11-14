/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the DLL.
*/

#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

struct node 
{
	struct node* next;
	struct node* prev;
	int data;
	node(int val): next(NULL), prev(NULL), data(val){};
};

struct nodeT
{
	struct nodeT* right;
	struct nodeT* left;
	int data;
};

void convertToDLL (struct nodeT* tree, struct node* list)
{
	if (tree == NULL)
	{
		return;
	}

	convertToDLL(tree->left, list);

	if (list == NULL)
	{
		list = node(tree->data);
	}
	else
	{
		node* newNode = node(tree->data);
		list->next = newNode;
		newNode->prev = list;
		list = newNode;
	}

	convertToDLL(tree->right, list);
}
