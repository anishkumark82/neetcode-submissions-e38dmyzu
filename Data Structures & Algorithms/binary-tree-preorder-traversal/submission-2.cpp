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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *cur = root;
        stack<TreeNode *> s; // used to store the right nodes
        vector<int> out;
        while(cur != nullptr || !s.empty())
        {
            if(cur != nullptr) // I am on a node to process
            {
                out.push_back(cur->val);
                if(cur->right)
                    s.push(cur->right);
                cur = cur->left;
            }
            else // if(!s.empty())
            {
                cur = s.top();
                s.pop();
            }
        }
        return out;
    }
};