/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 

*/

class Solution {
public:
 
    // Reverses the linkedList which starts from head, and extends to size nodes. 
    // Returns the end node. 
    // Also sets the head->next as endNode->next. 
    ListNode *reverseLinkedList(ListNode *head, int size) {
    if (size <= 1) return head; 
        ListNode *cur = head, *nextNode = head->next, *tmp;

    for (int i = 0; i < (size - 1); i++) {
        tmp = nextNode->next;
        nextNode->next = cur; 
        cur = nextNode;
        nextNode = tmp; 
    }

    head->next = nextNode;
    return cur;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
    // Introduce dummyhead to not handle corner cases. 
    ListNode* dummyHead = new ListNode(0); 
    dummyHead->next = head; 

    // Figure out the start node of the sublist we are going to reverse
      ListNode* prev = dummyHead;
    ListNode* cur = head; 
    int index = 1;
    while (index < m) {
        prev = cur;
        cur = cur->next;
        index++;
    }

    // At this point, we have start of sublist in cur, prev of startSubList in prev.
    // Lets reverse the sublist now. 
    ListNode* endSubList = reverseLinkedList(cur, n - m + 1);
    prev->next = endSubList; 

    return dummyHead->next;
    }
};
