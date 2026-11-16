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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        TreeNode *cur = root;
        stack<TreeNode *> s;
        while(cur != nullptr || !s.empty())
        {
            if(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            else // cur is null
            {
                cur = s.top();
                s.pop();
                out.push_back(cur->val);
                cur = cur->right;
            }
        }
        return out;
    }
};