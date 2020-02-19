/*

You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given. 

Note: No head reference is given to you.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains the data of the linked list. The last line contains the node to be deleted.

Output Format:
For each testcase, in a newline, print the linked list after deleting the given node.

Your Task:
This is a function problem. You only need to complete the function deleteNode that takes reference to the node that needs to be deleted. The printing is done automatically by the driver code.

*/



/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/


void deleteNode(Node *node)
{
    if (node == NULL) {
        cout << "The node is empty" << endl;
        return;
    }
    
    if (node->next == NULL) {
        cout << "Cannot free last node because that will result in a dangling pointer. Need the head node to delete this or DLL implementation." << endl;
        return;
    }
    
   Node* cur = node;
   Node* _oneNext = node->next;
   Node* _twoNext = node->next->next;
   
   cur->data = _oneNext->data;
   cur->next = _twoNext;
   
   delete _oneNext;
   
}
