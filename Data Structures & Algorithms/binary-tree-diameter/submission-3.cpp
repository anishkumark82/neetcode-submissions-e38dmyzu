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
    // return the max of left or right subtree
    int _dfs(TreeNode *root, int& maxLen)
    {
        if(root == nullptr)  
            return 0;
        
        int leftHt = _dfs(root->left, maxLen);
        int rightHt = _dfs(root->right, maxLen);

        maxLen = max(leftHt + rightHt, maxLen);
        return 1+max(leftHt, rightHt);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen = 0;
        _dfs(root, maxLen);        
        return maxLen;
    }
};
