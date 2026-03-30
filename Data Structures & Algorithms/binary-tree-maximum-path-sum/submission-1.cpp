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
    int _dfs(TreeNode* root, int &maxPath)
    {
        if(root == nullptr)
            return 0;
        
        int leftMax = _dfs(root->left, maxPath);
        int rightMax = _dfs(root->right, maxPath);
        int curPath = root->val + leftMax + rightMax;
        maxPath = max(curPath, maxPath);
        return max(max(leftMax, rightMax) + root->val, 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        _dfs(root, maxPath);
        return maxPath;
    }
};
