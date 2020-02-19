/*
*
* A program to find the intersection point of two lists.
* 
* Created By: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node 
{
	int data;
	struct node* next;
};

/*
* check if there is an intersection between two lists.
* return 0 if there is an intersection.
*/
int intersection (struct node* x, struct node* y) 
{
	struct node* cur1 = x, *cur2 = y;
	while (cur1->next != NULL) 
	{
		cur1 = cur1->next;
	}
	while (cur2->next != NULL) 
	{
		cur2 = cur2->next;
	}
	if (cur1 == cur2) {
		return 0;
	}
	else
	{
		return 1;
	}
}

int countNodes (struct node* x) 
{
	int count = 0;
	struct node* cur = x;
	while (cur->next != NULL) 
	{
		cur = cur->next;
		count++;
	}
	return count;
}

int compareAndGetIntersection (struct node* x, struct node* y)
{
	int xx = countNodes(x);
	int yy = countNodes(y);
	int result;

	if (xx > yy) 
	{
		result = abs(xx-yy);
		return getIntersectionNode(result, x, y);
	}
	else 
	{
		result = abs(yy-xx);
		return getIntersectionNode(result, y, x);
	}
}

/*
* The first argument is generally assumed to be the longer list in this program
*/
int getIntersectionNode (int i, struct node *x, struct node *y) 
{
	struct node* cur1 = x;
	struct node* cur2 = y;
	int count = 0;

	while (count != i) 
	{	
		if (cur1 == NULL)
		{
			return -1;
		} 
		cur1 = cur1->next;
		count++;
	}

	while (cur1 != NULL && cur2 != NULL) 
	{
		if (cur1 == cur2) {
			return cur1->data;
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return -1;
}

/*
* The main function
*/
int main () 
{
	/*
	The lists are of the following orientation:
	1->2->3->4->5
	      ^	
	   1->|
	*/
	 struct node* one;
	 one = (struct node*)malloc(sizeof(struct node));
	 if (one == NULL) 
	 {
	 	printf("Error in memory allocation!\n");
	 	exit(1);
	 }
	 one->data = 1;

	 struct node* two;
	 two = (struct node*)malloc(sizeof(struct node));
	 if (two == NULL) 
	 {
	 	printf("Error in memory allocation!\n");
	 	exit(1);
	 }
	 two->data = 2;
	 one->next = two;

	 struct node* three;
	 three = (struct node*)malloc(sizeof(struct node));
	 if (three == NULL)
	 {
	 	printf("Error in memory allocation!\n");
	 	exit(1);
	 }
	 three->data = 3;
	 two->next = three;
	 
	 struct node* four;
	 four = (struct node*)malloc(sizeof(struct node));
	 if (one == NULL) 
	 {
	 	printf("Error in memory allocation!\n");
	 	exit(1);
	 }
	 four->data = 4;
	 three->next = four;
	 
	 struct node* five;
	 five = (struct node*)malloc(sizeof(struct node));
	 if (one == NULL) 
	 {
	 	printf("Error in memory allocation!\n");
	 	exit(1);
	 }
	 five->data = 5;
	 four->next = five;

	 struct node* one_a;
	 one_a = (struct node*)malloc(sizeof(struct node));
	 if (one == NULL) 
	 {
	 	printf("Error in memory allocation!\n");
	 	exit(1);
	 }
	 one_a->data = 1;
	 one_a->next = three;
	 five->next = NULL;

	 /* check if there is an intersection first */
	 if (intersection(one, one_a) == 0) 
	 {
		 int result = compareAndGetIntersection(one, one_a);

		 if (result != -1) 
		 {
		 	printf("The intersection node is %d\n", result);
		 }
	}
	return 0;
}	

/* CPP Implementation

    int n = abs(count1 - count2);
    count = n;
    
    if (count1 > count2) {
        cur1 = head1;
    } else {
        cur1 = head2;
    }
    
 */
