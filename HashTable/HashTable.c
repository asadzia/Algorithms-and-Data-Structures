/*
*
* A hash table implementation in C.
*
*
* Created By: Asad Zia.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Predefined hash table sizes. The size should be always a prime
 * for less collisions.
 */
#define HASH_SIZE_1009         1009 /* 10^3+9 */
#define HASH_SIZE_10007       10007 /* 10^4+7 */
#define HASH_SIZE_100003     100003 /* 10^5+3 */
#define HASH_SIZE_1000003   1000003 /* 10^6+3 */
#define HASH_SIZE_10000019 10000019 /* 10^7+19 */

/* structure definitions */
struct node
{
	char* str;
	struct node* next;
};

struct hash_table
{
	int size;
	struct node** table;
};

/*
* A function to create and initialize a hash table
*/
struct hash_table* create_hashTable (int size)
{
	int i;
	struct hash_table* x = NULL;

	if (size < 1)
	{
		printf("Size of the table is too small! Exiting...\n");
		exit(1);
	}

	x = (struct hash_table*)malloc(sizeof(struct hash_table));
	if (x == NULL)
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}

	x->table = (struct node**)malloc(sizeof(struct node*) * size);
	if (x->table == NULL)
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}

	for (i = 0; i < size; i++)
	{
		x->table[i] = NULL;
	}

	x->size = size;
	return x;
}

/*
* The hash function: I basically multiply the hash value with 32 by using shifting since multiplication itself is slower.
* Then I subtract the original variable to get an almost unique hashing value.
*/
unsigned int hashFunction (struct hash_table *x, char* str)
{
	int hash = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		hash = str[i] + (hash << 5) - hash;
	}

	/* to make sure that our hash value fits the table index */
	return (hash % x->size);
}

/*
* A function to lookup a string in the hash table
*/
struct node* lookUp (struct hash_table *x, char *str)
{
	int hash = hashFunction(x, str);
	struct node* cur = x->table[hash];

	while (cur != NULL)
	{
		if (strcmp(cur->str, str) == 0)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

/*
* A function to add an element to the hash table
*/
void addElement (struct hash_table *x, char* str)
{
	int hash = hashFunction(x, str);
	struct node* myNode;

	myNode = (struct node*)malloc(sizeof(struct node));
	if (myNode == NULL)
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}

	myNode->str = strdup(str); /* allocate memory for the string to be stored in the hash table */

	if (lookUp(x, str) == NULL) {	/* if the string does not already exist in the hash table */
		if (x->table[hash] == NULL)	/* if there is no collision */
		{
			x->table[hash] = myNode;
			myNode->next = NULL;
		}
		else	/* if there is a collision then prepend */
		{
			myNode->next = x->table[hash];
			x->table[hash] = myNode;
		}
	}
}

/*
* A function to free a hash table structure
*/
void FreeTable (struct hash_table *x)
{
	int i;
	struct node* cur, *temp;

	if (x != NULL)
	{
		for (i = 0; i < x->size; i++)
		{
			cur = x->table[i];
			while (cur != NULL)
			{
				temp = cur->next;
				free(cur->str); /* free the memory of strings */
				free(cur);		/* free each node in the list */
				cur = temp;
			}

		}

		free(x->table);	/* free the table */
		free(x);		/* free the hash table structure */
	}
}

/*
* The mian function
*/
int main ()
{
	struct hash_table* myHashTable = create_hashTable(HASH_SIZE_1009);
	addElement(myHashTable, "Steven Wilson");
	addElement(myHashTable, "David Gilmour");
	addElement(myHashTable, "Gavin Harrison");
	addElement(myHashTable, "Kirk Hamett");
	addElement(myHashTable, "Dave Mustaine");
	addElement(myHashTable, "Toni Iommi");
	addElement(myHashTable, "Jimmy Page");
	addElement(myHashTable, "Roger Waters");

	struct node* Test = lookUp(myHashTable, "Steven Wilson");
	printf("Result: %s\n", Test->str);

	FreeTable(myHashTable);
	return 0;
}

/*
* Also possible to use key-value pairs.
* Just add a key attribute to the struct defined above.
* And then traverse the hash table using the key to
* find the the desired value.
*/
