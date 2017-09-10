/* A program in C++ for finding the top-view of a tree.
   The code also has details on how to print the tree in vertical order as well
*/

#include <iostream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

struct node
{
    struct node* right;
    struct node* left;
    int data;
};

void setVerticalNodes (node* root, int hd, map<int, vector<int> > &checker)
{
    if (root == NULL)
    {
        return;
    }

    checker[hd].push_back(root->data);

    setVerticalNodes(root->left, hd - 1, checker);
    setVerticalNodes(root->right, hd + 1, checker);
}


void topView(node * root)
{
    if (root == NULL)
    {
        return;
    }
    
    int hd = 0;
    map <int, vector<int> > checker;

    setVerticalNodes(root, hd, checker);

    map<int, vector<int> >::iterator it;

    for (it = checker.begin(); it != checker.end(); it++)
    {
        /* To get vertial view of tree with ALL nodes, just add for loop to read all elements of the vector in the map */
        cout << it->second[0] << " ";
    }  
}

void inorder (node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main (int argc, char** args)
{
    node* root = new node;
    root->data = 1;
    root->left =  NULL;
    root->right = new node;
    root->right->left = NULL;
    root->right->data = 2;
    root->right->right = new node;
    root->right->right->data = 5;
    root->right->right->left = new node;
    root->right->right->left->left = NULL;
    root->right->right->left->data = 3;
    root->right->right->left->right = new node;
    root->right->right->left->right->data = 4;
    root->right->right->right = new node;
    root->right->right->right->data = 6;
    root->right->right->right->right = NULL;
    root->right->right->right->left = NULL;

    //inorder(root);
    topView(root);

    return 0;
}


/*
SIMPLER FUNCTION

void helpone (node * root)
{
    if (root == NULL)
    {
        return;
    }
    
    helpone(root->left);
    cout << root->data << " ";
}

void helptwo (node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    cout << root->data << " ";
    helptwo(root->right);
}

void topView(node * root) {
    helpone(root);
    helptwo(root->right);   
}

*/
