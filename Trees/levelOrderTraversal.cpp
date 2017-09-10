
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void printHelper (node* root, int hd)
{
    if (root == NULL)
    {
        return;
    }
    
    if (hd == 0)
    {
        cout << root->data << " ";
        return;
    }
    
    printHelper(root->left, hd - 1);
    printHelper(root->right, hd - 1);
}

int findHeight (node* root)
{
    if (root == NULL)
    {
        return  -1;
    }
    
    int left = findHeight(root->left) + 1;
    int right = findHeight(root->right) + 1;
    
    if (left > right)
    {
        return left;
    }
    else
    {
        return right;
    }
}

void levelOrder(node * root) {
    
    if (root == NULL)
    {
        return;
    }
    
    int h = findHeight(root);  // default height of the root node
    
    for (int i = 0; i <= h; ++i)
    {
        printHelper(root, i);
    }
      
}
