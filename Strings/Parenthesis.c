/*
* A program to check if the parenthesis are complete in an expression in C
*
* Created by Asad Zia
*/

#define MAX 20

#include <stdio.h>
#include <stdlib.h>

/* the structure defiend for the stack */
struct stack
{
	int count;
	char *container;
};

/* 
* Initializing the stack
*/
void initialize (struct stack* x)
{
	x->container = (char*)malloc(sizeof(char) * MAX);
	if (x->container == NULL)
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}
	x->count = 0;
}

/*
* The push function
*/
void push (struct stack* x, char y)
{
	int flag = 0;
	if (x == NULL)
	{
		printf("Stack does not exist!\n");
		exit(1);
	}

	if (x->count == MAX)
	{
		printf("Stack Overflow!\n");
		flag = 1;
	}

	if (flag == 0)
	{
		x->count++;
		x->container[x->count] = y;
	}
}

/*
* The pop fucntion
*/
char pop (struct stack* x)
{
	int flag = 0;
	if (x == NULL)
	{
		printf("Stack does not exist!\n");
		exit(1);
	}

	if (x->count == 0)
	{
		printf("Stack Underflow\n");
		flag = 1;
	}

	if (flag == 0)
	{
		char result = x->container[x->count];
		x->count--;
		return result;
	}
}

/*
* The function to check the balance of the parenthesis
*/
int parenthesisBalance (char x, char y)
{
	if (x == '{' && y == '}') 
	{
		return 0;
	}
	else if (x == '(' && y == ')')
	{
		return 0;
	}
	else if (x == '[' && y == ']'){
		return 0;
	}
	else
	{
		return 1;
	}
}

/*
* The function for deciding if the parenthesis are indeed balanced in a string
*/
void checkParenthesis (struct stack* x, char* str)
{
	int i, flag = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
		{
			push(x, str[i]); 

		}

		if (str[i] == '}' || str[i] == ']' || str[i] == ')')
		{
			char result = pop(x);
			int answer = parenthesisBalance(result, str[i]);
			if (answer == 1)
			{
				printf("Parenthesis are not balanced!\n");
				flag = 1;
				break;
			} 

		}
	}
	if (flag == 0) 
	{
		printf("Parenthesis are balanced!\n");
	}
}

/*
* Deallocate the stack memory
*/
void freeStack (struct stack *x)
{
	free(x->container);
}

/*
* The main function
*/
int main ()
{
	struct stack myStack;
	char* str = "[{()}]()[{}]";
	initialize(&myStack);
	checkParenthesis(&myStack, str);
	freeStack(&myStack);
	return 0;
}

/*

A C++ Approach:

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct stack
{
    vector<char> arr;
};

void push (stack &x, char data)
{
    x.arr.push_back(data);
}

char pop (stack &x)
{
    char temp = x.arr[x.arr.size() - 1];
    x.arr.pop_back();
    return temp;
}

bool parenthesis (char s, char e)
{
    if (s == '(' && e == ')')
    {
        return true;
    }

    if (s == '{' && e == '}')
    {
        return true;
    }

    if (s == '[' && e == ']')
    {
        return true;
    }

    return false;
}

bool check (stack &x, string str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(x, str[i]);
            continue;
        }

        if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            char temp = pop(x);
            bool result = parenthesis(temp, str[i]);

            if (!result)
            {
                cout << "UNBLAANCED" << endl;
                return false;
            }
        }
    }

    if (x.arr.size() > 0)
    {
        cout << "UNBALANCED" << endl;
        return false;
    }

    return true;
}

int main ()
{
  stack x;
  string str = "(([[]])){}";
  
  if (check(x, str))
  {
    cout << "GOOD" << endl;
  }
  
  return 0;
}

*/
