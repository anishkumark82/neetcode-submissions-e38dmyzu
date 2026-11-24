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
    bool _dfs(TreeNode *root, int minVal = -1000000001, int maxVal =  1000000001)
    {
        if(root == nullptr)
            return true;
        if(root->val <= minVal || root->val >= maxVal)
            return false;
        return _dfs(root->left, minVal, root->val) && _dfs(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return _dfs(root);
    }
};
