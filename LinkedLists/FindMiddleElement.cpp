// Find the middle of a linked list

#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node(int x):data(x), next(NULL){};
};

int findMiddle (Node* head) {

  // empty list or just one element in the list
  if (head == NULL) {
    return -1;
  } else if (head->next == NULL) {
    return head->data;
  }

  // use slow and faster pointer to find the exact middle element

  Node* slow = head;
  Node* fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->data;

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

  for (int i = 0; i <= 6; ++i) {
    head = append(head, i);
    printList(head);
    cout << "Middle: " << findMiddle(head) << endl;
  }

  return 0;
} 
