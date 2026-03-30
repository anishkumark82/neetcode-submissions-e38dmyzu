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
    int balHelper(TreeNode *root, bool& isBalanced)
    {
        if(root == nullptr)
            return -1;
        
        int leftHt = 1 + balHelper(root->left, isBalanced);
        int rightHt = 1 + balHelper(root->right, isBalanced);

        if(abs(leftHt - rightHt) > 1)
            isBalanced = false;
        return max(leftHt, rightHt);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        balHelper(root, isBalanced);
        return isBalanced;    

    }
};
