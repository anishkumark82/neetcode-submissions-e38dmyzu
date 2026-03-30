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
    bool isTreesIdentical(TreeNode* root, TreeNode* subRoot)
    {
        if(root == nullptr && subRoot == nullptr)
            return true;
        
        if(root == nullptr)
            return false;
        
        if(subRoot == nullptr)
            return false;
        
        return root->val == subRoot->val && 
                            isTreesIdentical(root->left, subRoot->left) && 
                            isTreesIdentical(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr)
            return true;
        
        if(root == nullptr)
            return false;
        
        if(root->val == subRoot->val)
            if(isTreesIdentical(root, subRoot))
                return true;
        // The current sub-trees doesnt match
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
