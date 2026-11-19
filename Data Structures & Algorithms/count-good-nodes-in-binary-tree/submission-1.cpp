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
    int _dfs(TreeNode* root, int maxVal)
    {
        if(root == nullptr)
            return 0;
        
        int cnt = (root->val >= maxVal) ? 1 : 0;

        return cnt + _dfs(root->left, max(root->val, maxVal)) + _dfs(root->right, max(root->val, maxVal));        
    }
public:
    int goodNodes(TreeNode* root) {
        return _dfs(root, -101);
    }
};
