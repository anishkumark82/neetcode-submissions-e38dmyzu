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
    int checkBalanced(TreeNode* root, bool &balanced)
    {
        if(!balanced)
            return 0;
        
        if(root == nullptr)
            return 0;

        int leftHt = checkBalanced(root->left, balanced);
        int rightHt = checkBalanced(root->right, balanced);

        if(abs(leftHt - rightHt) > 1)
        {
            balanced = false;
            return 0;
        }
        return 1 + max(leftHt, rightHt);

    }
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        checkBalanced(root, balanced);
        return balanced;
        
    }
};
