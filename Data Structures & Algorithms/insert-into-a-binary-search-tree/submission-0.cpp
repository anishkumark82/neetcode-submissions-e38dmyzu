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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Question assumes no node of val exists
        TreeNode* node = new TreeNode(val);
        if(root == nullptr)
            return node;
        
        if(val > root->val)
            root->right = insertIntoBST(root->right, val);
        else 
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};