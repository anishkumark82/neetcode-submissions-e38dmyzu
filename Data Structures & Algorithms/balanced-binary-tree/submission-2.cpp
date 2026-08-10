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
    int checkBalanced(TreeNode *root, bool &balanced)
    {
        if(!balanced)
            return 0;
        
        if(root == nullptr)
            return -1;
        
        int lHt = checkBalanced(root->left, balanced);
        int rHt = checkBalanced(root->right, balanced);
        if(abs(lHt-rHt) > 1)
            balanced = false;
        
        return 1 + max(lHt, rHt);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        checkBalanced(root, balanced);
        return balanced;
    }
};
