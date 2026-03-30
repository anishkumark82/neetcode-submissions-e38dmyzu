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
    bool _isValidBSTHelper(TreeNode* root, int minVal, int maxVal)
    {
        if(root == nullptr)
            return true;
        
        return (root->val > minVal && root->val < maxVal) && 
                (_isValidBSTHelper(root->left, minVal, root->val)) && 
                (_isValidBSTHelper(root->right, root->val, maxVal)); 
    }
public:
    bool isValidBST(TreeNode* root) {
        return _isValidBSTHelper(root, INT_MIN, INT_MAX);
    }
};
