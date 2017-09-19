/* A program to merge two sorted linked lists */

/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
    Node* head; 
    Node* temp;
    
  if (headA == NULL)
  {
      return headB;
  }
    else if (headB == NULL)
    {
        return headA;
    }
    
    if (headA->data <= headB->data)
    {
        head = headA;
        temp = head;
    }
    else
    {
        head = headB;
        temp = head;
    }
   
    temp = NULL;
    Node *curA = headA;
    Node* curB = headB;
    
    while (curA != NULL && curB != NULL)
    { 
        if (curA->data <= curB->data)
        {
            if (temp == NULL)
            {
                temp = curA;
            }
            else
            {
                temp->next = curA;
                temp = curA;
            }
            curA = curA->next;
        }
        else
        {
            if (temp == NULL)
            {
                temp = curB;
            }
            else
            {
                temp->next = curB;
                temp = curB;
            }
            curB = curB->next;
        }
    }

    if (curA != NULL)
    {
      temp->next = curA;
    }
    else if (curB != NULL)
    {
        temp->next = curB;
    }
    
    return head;
}
