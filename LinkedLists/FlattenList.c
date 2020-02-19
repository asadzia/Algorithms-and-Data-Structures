/*

Flattening a Linked List
Given a linked list where every node represents a linked list and contains two pointers of its type:
(i) Pointer to next node in the main list (we call it ‘right’ pointer in below code)
(ii) Pointer to a linked list where this node is head (we call it ‘down’ pointer in below code).
All linked lists are sorted. See the following example

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
Write a function flatten() to flatten the lists into a single linked list. The flattened linked list should also be sorted. For example, for the above input list, output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50.

*/

#include <stdio.h> 
#include <stdlib.h> 
  
// A Linked List Node 
typedef struct Node 
{ 
    int data; 
    struct Node *right; 
    struct Node *down; 
} Node; 
  
/* A utility function to insert a new node at the begining 
   of linked list */
void push (Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = (Node *) malloc(sizeof(Node)); 
    new_node->right = NULL; 
  
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list off the new node */
    new_node->down = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  
/* Function to print nodes in the flattened linked list */
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->down; 
    } 
} 
  
// A utility function to merge two sorted linked lists 
Node* merge( Node* a, Node* b ) 
{ 
    // If first list is empty, the second list is result 
    if (a == NULL) 
        return b; 
  
    // If second list is empty, the second list is result 
    if (b == NULL) 
        return a; 
  
    // Compare the data members of head nodes of both lists 
    // and put the smaller one in result 
    Node* result; 
    if (a->data < b->data) 
    { 
        result = a; 
        result->down = merge( a->down, b ); 
    } 
    else
    { 
        result = b; 
        result->down = merge( a, b->down ); 
    } 
  
    return result; 
} 
  
// The main function that flattens a given linked list 
Node* flatten (Node* root) 
{ 
    // Base cases 
    if (root == NULL || root->right == NULL) 
        return root; 
  
    // Merge this list with the list on right side 
    return merge( root, flatten(root->right) ); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    Node* root = NULL; 
  
    /* Let us create the following linked list 
       5 -> 10 -> 19 -> 28 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
    */
    push( &root, 30 ); 
    push( &root, 8 ); 
    push( &root, 7 ); 
    push( &root, 5 ); 
  
    push( &( root->right ), 20 ); 
    push( &( root->right ), 10 ); 
  
    push( &( root->right->right ), 50 ); 
    push( &( root->right->right ), 22 ); 
    push( &( root->right->right ), 19 ); 
  
    push( &( root->right->right->right ), 45 ); 
    push( &( root->right->right->right ), 40 ); 
    push( &( root->right->right->right ), 35 ); 
    push( &( root->right->right->right ), 20 ); 
  
    // Let us flatten the list 
    root = flatten(root); 
  
    // Let us print the flatened linked list 
    printList(root); 
  
    return 0; 
} 

/*
*
* A program to flatten a linked list in C.
*
* Created by: Asad Zia
*/

/*

#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *next;
	struct node *child;
};

struct node* newNode (int x)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Error in memroy allocation\n");
		exit(1);
	}

	temp->next = temp->child = NULL;
	temp->data = x;
	return temp;
}

struct node* flattenList (struct node* x)
{
	struct node* current = x, *tail = x, *temp;

	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	while (current != NULL)
	{
		if (current->child != NULL)
		{
			tail->next = current->child;

			while (tail->next != NULL)
			{
				tail = tail->next;
			}
		}

		current = current->next;
	}

	return x;
}

void printList (struct node* x)
{
	struct node* cur = x;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main ()
{*/
	/*
	Making the following list:
	1->2->3->4->5
	|        |
	6->7	 8->9
				|
				10
	*/
/*
	struct node *myList_one = newNode(1);
	struct node *myList_two = newNode(2);
	struct node *myList_three = newNode(3);
	struct node *myList_four = newNode(4);
	struct node *myList_five = newNode(5);
	struct node *myList_six = newNode(6);
	struct node *myList_seven = newNode(7);
	struct node *myList_eight = newNode(8);
	struct node *myList_nine = newNode(9);
	struct node *myList_ten = newNode(10);

	myList_one->next = myList_two;
	myList_two->next = myList_three;
	myList_three->next = myList_four;
	myList_four->next = myList_five;
	myList_one->child = myList_six;
	myList_six->next = myList_seven;
	myList_four->child = myList_eight;
	myList_eight->next = myList_nine;
	myList_nine->child = myList_ten;

	myList_one = flattenList(myList_one);
	printList(myList_one);
	return 0;
}
*/
