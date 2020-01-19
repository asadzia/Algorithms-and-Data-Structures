/*

Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is much greater than number of nodes on a level.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findHeight (TreeNode* A) {
    if (A == NULL) {
        return -1;
    }
    
    int left = findHeight(A->left) + 1;
    int right = findHeight(A->right) + 1;
    
    if (left > right) {
        return left;
    }
    return right;
}

void levelOrderHelper (TreeNode* A, int h, vector<int> &result) {
    
    if (A == NULL) {
        return;
    }
    
    if (h > 0) {
        levelOrderHelper(A->left, h - 1, result);
        levelOrderHelper(A->right, h - 1, result);
    } else {
        result.push_back(A->val);
    }
}
 
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    int h = findHeight(A);
    vector<vector<int>> ans;
    
    for (int i = 0; i <= h; ++i) {
        vector<int> result;
        levelOrderHelper(A, i, result);
        ans.push_back(result);
    }
    return ans;
}
