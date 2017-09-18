    /* A program to find the maximum sum from leaf to root path for a binary search tree in C++ */

    #include <iostream>
    #include <climits>
    #include <vector>

    using namespace std;

    struct node
    {
        int data;
        node* right;
        node* left;
        node(int val)
        {
            right = left = NULL;
            data = val;
        };
    };

    static node* leafNode = NULL;

    // A method for finding the maximum sum from root to leaf for a BINARY TREE (not a search tree)
    int maxSum (node* root, int val, int& max)
    {   
        // used references for both max and max_val since these values change.
        // https://stackoverflow.com/questions/2564873/how-do-i-use-reference-parameters-in-c
        int cur = val;

        if (root == NULL)
        {
            return 0;
        }

        cur = cur + root->data;
        
        if (root->left == NULL && root->right == NULL)
        {
            if (max < cur)
            {
                max = cur;
                cur = 0;
                leafNode = root;
                cout << "HELLO " << max<< endl;
            }
        }

        maxSum(root->left, cur, max);
        maxSum(root->right, cur, max);

        return max;
    }

    // Method for printing the path of all the nodes for max sum.
    bool printNodesPath(node* root)
    {
        if (root == NULL)
        {
            return false;
        }

        if (root == leafNode)
        {
            cout << root->data << " ";
            return true;
        }

        // if leaf is found then recursively print all the nodes in the path leading to that leaf
        if (printNodesPath(root->left))
        {
            cout << root->data << " ";
        }

        // if leaf is found then recursively print all the nodes in the path leading to that leaf
        if (printNodesPath(root->right))
        {
            cout << root->data << " ";
        }
    }


    int maxPathSumLeafs (node* root, int max)
    {
        int result_one;
        int result_two;
        int max_val = max;
        int cur;

        if (root == NULL)
        {
            return 0;
        }

        int res = INT_MIN;
        int res1 = INT_MIN;
        result_one = maxSum(root->right, 0, res);
        result_two = maxSum(root->left, 0, res1);
        cur = result_one + result_two + root->data;
        cout << result_one << " + " << result_two << " " <<  root->data << endl;

        if (cur > max_val)
        {
            max_val = cur;
            //cout << result_one << " + " << result_two << " " <<  max_val << endl;
        }

        maxPathSumLeafs(root->right, max_val);
        maxPathSumLeafs(root->left, max_val);

        return max_val;
    }

    // the main method
    int main (int argc, char ** args)
    {
        // constructing a tree
        node* root = new node(10);
        root->left = new node(-2);
        root->right = new node(7);
        root->left->left = new node(8);
        root->left->right = new node(-4);

        int res = INT_MIN;
        int sum = maxSum(root, 0, res);

        cout << "Sum: " << sum << endl;

        cout << "Path: ";
        printNodesPath(root);
        cout << endl;

        cout << "Max sum from leaf to leaf: " << endl;
        cout << maxPathSumLeafs(root, INT_MIN) << endl;


        return 0;
    }
