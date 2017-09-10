

/*
Node is defined as 

typedef struct node
{
   int data;
   node *left;
   node *right;
}node;

*/

// The Lowest common ancestor would be the root at any given point int he tree

node *lca(node *root, int v1,int v2)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    if (root->data > v1 && root->data > v2)
    {
        root = lca(root->left, v1, v2);
    }
    
    if (root->data < v1 && root->data < v2)
    {
        root = lca(root->right, v1, v2);
    }
    
    return root;
}

