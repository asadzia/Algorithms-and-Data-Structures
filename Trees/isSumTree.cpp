/*

Check if a given Binary Tree is SumTree
Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree.

          26
        /   \
      10     3
    /    \     \
  4      6      3
  
  */


	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

bool isSumTree(struct Node* node);

/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     cout << isSumTree(root) << endl;
  }
  return 0;
}// } Driver Code Ends

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

int sumHelper (Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    return root->data + sumHelper(root->left) + sumHelper(root->right);
}

// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* root)
{
     if (root == NULL || (root->left == NULL && root->right == NULL)) {
         return true;
     }
     
     int left = sumHelper(root->left);
     int right = sumHelper(root->right);
     
     if (left + right == root->data &&
         isSumTree(root->left) && isSumTree(root->right)) {
             return true;
        }
        
    return false;
}
