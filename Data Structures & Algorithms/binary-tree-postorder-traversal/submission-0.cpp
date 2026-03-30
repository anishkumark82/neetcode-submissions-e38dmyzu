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
    void postOrdTrav(TreeNode* root, vector<int> &out)
    {
        if(root == nullptr)
            return;
        
        postOrdTrav(root->left, out);
        postOrdTrav(root->right, out);
        out.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // L R N
        vector<int> out;
        postOrdTrav(root, out);
        return out;
    }
};