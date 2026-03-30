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
    int _dfs(TreeNode* root, int& maxLen)
    {
        if(root == nullptr) 
            return -1;
        
        int lPath = 1 + _dfs(root->left, maxLen);
        int rPath = 1 + _dfs(root->right, maxLen);
        maxLen = max(lPath + rPath, maxLen);
        return max(lPath, rPath);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen = 0;
        _dfs(root, maxLen);
        return maxLen;
    }
};
