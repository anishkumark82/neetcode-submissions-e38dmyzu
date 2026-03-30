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
    bool isValidBSTHelper(TreeNode* root, int minV, int maxV)
    {
        if(root == nullptr)
            return true;

        return (root->val > minV && root->val < maxV) &&
               isValidBSTHelper(root->left, minV, root->val) &&
               isValidBSTHelper(root->right, root->val, maxV);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        return isValidBSTHelper(root, -1001, 1001);
    }
};
