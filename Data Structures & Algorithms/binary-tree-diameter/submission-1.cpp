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
    int diameterHelper(TreeNode* root, int &maxLen)
    {
        if(root == nullptr)
            return 0;
        
        int leftLen = diameterHelper(root->left, maxLen);
        int rightLen = diameterHelper(root->right, maxLen);
        maxLen = max(maxLen, leftLen + rightLen);
        return max(1+leftLen, 1+rightLen);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen = 0;
        diameterHelper(root, maxLen);
        return maxLen;
    }
};
