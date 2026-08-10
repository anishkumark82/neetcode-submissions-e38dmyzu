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
    void inorderHlper(TreeNode* root, vector<int> &out)
    {
        if(root == nullptr)
            return;
        
        inorderHlper(root->left, out);
        out.push_back(root->val);
        inorderHlper(root->right, out);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        inorderHlper(root, out);
        return out;    
    }
};