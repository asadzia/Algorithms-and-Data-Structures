/*
A program for inserting a node into a sorted doubly lnked list
*/

/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // create new node
    Node* newNode = new Node;
    newNode->data = data;
    
    if (head == NULL)
    {
        head = newNode;
        head->prev = NULL;
        head->next = NULL;
    }
    else
    {
        Node* cur = head;
        
        while (cur != NULL)
        {
            if (cur->data >= data && cur->prev == NULL)
            {
                cur->prev = newNode;
                newNode->next = cur;
                newNode->prev = NULL;
                head = newNode;
                break;
            }
            else
            {
                if (cur->data >= data && cur->prev->data < data)
                {
                   cur->prev->next = newNode;
                   newNode->prev = cur->prev;
                   cur->prev = newNode;
                   newNode->next = cur;
                   break;
                }

                if (cur->next == NULL)
                {
                    cur->next = newNode;
                    newNode->prev = cur;
                    newNode->next = NULL;
                    break;
                }
            }
            
            cur = cur->next;
        }
    }
    
    return head;
}

/*

Given a reference to the head of a doubly-linked list and an integer, , create a new Node object having data value  and insert it into a sorted linked list.

Complete the Node* SortedInsert(Node* head, int data) method in the editor below. It has two parameters:

: A reference to the head of a doubly-linked list of Node objects.
: An integer denoting the value of the  field for the Node you must insert into the list.
The method must insert a new Node into the sorted (in ascending order) doubly-linked list whose data value is without breaking any of the list's double links or causing it to become unsorted.

Note: Recall that an empty list (i.e., where ) and a list with one element are sorted lists.

Input Format

Do not read any input from stdin. Hidden stub code reads in the following sequence of inputs and passes and  to the method:

The first line contains an integer, , denoting the number of lists that will be checked. The  subsequent lines describe the elements to insert into each list over two lines:

The first line contains an integer, , denoting the number of elements that will be inserted into the list.
The second line contains  space-separated integers describing the respective data values that your code must insert into the list during each call to the method.
Output Format

Do not print anything to stdout. Your method must return a reference to the  of the same list that was passed to it as a parameter. The custom checker for this challenge checks the list to ensure it hasn't been modified other than to properly insert the new Node in the correct location.

Sample Input

1
3
2 5 4
Sample Output

2 4 5
Explanation

We start out with an empty list. We insert a node with . The list becomes . We return .
The head of the previously modified list is passed to our method as an argument. We insert a node with . The list becomes . We return .
The head of the previously modified list is passed to our method as an argument. We insert a node with . The list becomes . We return .
Hidden stub code then prints the final list as a single line of space-separated integers.

*/
