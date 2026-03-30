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
        // Iterative approach
        vector<int> out;
        TreeNode *cur = root; // Node to be processed
        stack<TreeNode *> s;
        
        while(cur != nullptr || !s.empty())
        {
            while(cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            
            
            // pop the stack
            cur = s.top();
            s.pop();
            out.push_back(cur->val);
            cur = cur->right;
        }
        return out;
    }
};