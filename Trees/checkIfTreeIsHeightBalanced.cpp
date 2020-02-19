/*

How to determine if a binary tree is height-balanced?
A tree where no leaf is much farther away from the root than any other leaf. Different balancing schemes allow different definitions of “much farther” and different amounts of work to keep them balanced.
Consider a height-balancing scheme where following conditions should be checked to determine if a binary tree is balanced.
An empty tree is height-balanced. A non-empty binary tree T is balanced if:
1) Left subtree of T is balanced
2) Right subtree of T is balanced
3) The difference between heights of left subtree and right subtree is not more than 1.

The above height-balancing scheme is used in AVL trees. The diagram below shows two trees, one of them is height-balanced and other is not. The second tree is not height-balanced because height of left subtree is 2 more than height of right subtree.

*/

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return tree if passed  tree 
// is balanced, else false. 

int checkHeight (Node* root) {
    
    if (root == NULL) {
        return 0;
    }
    
    int left = checkHeight(root->left) + 1;
    int right = checkHeight(root->right) + 1;
    
    if (left > right) {
        return left;
    } else {
        return right;
    }
}

bool isBalanced(Node *root)
{
    if (root == NULL) {
        return true;
    }
 
    int left = checkHeight(root->left);
    int right = checkHeight(root->right);
    
    if (abs(left - right) <= 1 && isBalanced(root->right) && isBalanced(root->left)) {
        return true;
    } else {
        return false;
    }
}
