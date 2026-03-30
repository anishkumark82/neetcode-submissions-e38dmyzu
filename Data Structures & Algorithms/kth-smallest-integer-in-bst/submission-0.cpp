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
    void findkthSmallest(TreeNode* root, int &k, int &out)
    {
        if(root == nullptr)
            return;
        findkthSmallest(root->left, k, out);
        k--;
        if(k == 0)
            out = root->val;
        else
            findkthSmallest(root->right, k, out);
    }
    int kthSmallest(TreeNode* root, int k) {
        int out = -1;
        findkthSmallest(root, k, out);
        return out;
    }
};
