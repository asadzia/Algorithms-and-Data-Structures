#include <iostream>

using namespace std;

struct node
{
	struct node* next;
	int data;
	node(int x, node* val):next(val),data(x) {};
};

struct node* prepend (struct node* list, int val)
{
	node* newNode = new node(val, NULL);

	if (list == NULL)
  {
		return newNode;
	}

	newNode->next = list;

	return newNode;
}

struct node* append (struct node* list, int val)
{
	struct node* newNode = new node(val, NULL);

	if (list == NULL)
	{
		return newNode;
	}

	struct node* cur = list;

	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	cur->next = newNode;

	return list;
}

struct node* reverse (struct node* list)
{
	struct node* cur = list;
	struct node* temp = NULL;
	struct node* result = NULL;

	while (cur != NULL)
	{
      temp = cur->next;
      cur->next = result;
      result = cur;
      cur = temp;
	}

	return result;
}

void printList (struct node* list)
{
	struct node* cur = list;

	while (cur != NULL)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}

	cout << endl;
}

int main ()
{
	struct node* list = NULL;

	list = prepend(list, 1);
	list = prepend(list, 2);
	list = prepend(list, 3);
	list = append(list, 4);

	printList(list);

	list = reverse (list);

	printList(list);
	return 0;
}
