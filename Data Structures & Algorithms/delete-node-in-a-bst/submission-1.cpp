/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int findMin(TreeNode* root)
    {
        // Root should not be null
        if(root == nullptr)
            return -100001;
        
        TreeNode *cur = root;
        while(cur && cur->left)
            cur = cur->left;
        
        return cur->val;
    }
public:
    // 3 Cases
    // 1. delete leaf node
    // 2. Delete node with one child
    // 3. Delete node with 2 children
    TreeNode* deleteNode(TreeNode* root, int key) {
        // find node
        if(root == nullptr)
            return root;
        
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            TreeNode *tmp = root;
            // Case 1 and 2
            if(root->left == nullptr)
            {
                root = root->right;
                delete tmp;
            }
            else if(root->right == nullptr)
            {
                root = root->left;
                delete tmp;
            }
            // Case 3:
            else
            {
                int val = findMin(root->right);
                root->val = val;
                root->right = deleteNode(root->right, val);
            }
        }
        return root;

    }
};