// Merge Sorting a Linked List

// Merge Sort Linked list

#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node(int x):data(x), next(NULL){};
};

/*
Why init fast pointer with head->next?
Because we need (middle -1) element (one before the middle of linked list), so that we can break the list in to two halves and the second half starts from the mid of the original list.
If we initialize fast with source itself then we need to maintain extra 'previous' of slow pointer as I said we need element just before the middle node to divide the list into two halves.
*/
void frontBackSplit (Node* head, Node** front, Node** back) {

  Node* fast = head->next;
  Node* slow = head;

  while (fast != NULL) {

    fast = fast->next;
    if (fast != NULL) {
      slow = slow->next;
      fast = fast->next;
    }
  }

  *front = head;
  *back = slow->next;
  slow->next = NULL;
}

Node* SortedMerge(Node* a, Node* b) {

  Node* result = NULL;

  if (a == NULL) {
    return b;
  } else if (b == NULL) {
    return a;
  }

  if (a->data <= b->data) {
    result = a;
    result->next = SortedMerge(a->next, b);
  } else {
    result = b;
    result->next = SortedMerge(a, b->next);
  }

  return result;
}

void mergeSort(Node** head) {
  
  Node* a;
  Node* b;
  Node* cur = *head;

  if (cur == NULL) {
    return;
  }

  if (cur->next == NULL) {
    return;
  }

  frontBackSplit(cur, &a, &b);

  mergeSort(&a);
  mergeSort(&b);

  *head = SortedMerge(a, b);
}

Node* append(Node* head, int x) {
  if (head == NULL) {
    return new Node(x);
  }

  Node* cur = head;
  Node* n = new Node(x);

  while (cur->next != NULL) {
    cur = cur->next;
  }

  cur->next = n;
  return head;
}

void printList (Node* head) {
  Node* cur = head;

  while (cur != NULL) {
    cout << cur->data << " ";
    cur = cur->next;
  }

  cout << endl;
}

int main () {

  Node* head = NULL;

  head = append(head, 5);
  head = append(head, 6);
  head = append(head, 1);
  head = append(head, 3);
  head = append(head, 9);
  head = append(head, 34);

  printList(head);

  mergeSort(&head);
  printList(head);

  return 0;
} 
