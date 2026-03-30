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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *>s;
        stack<bool> visited;
        s.push(root);
        visited.push(false);
        vector<int> out;
        while(!s.empty())
        {
            TreeNode* cur = s.top();
            bool v = visited.top();
            s.pop();
            visited.pop();

            if(v) // Already visited
                out.push_back(cur->val);
            else if(cur != nullptr) // Because we also push nullptrs
            {
                s.push(cur);
                visited.push(true);
                s.push(cur->right);
                visited.push(false);
                s.push(cur->left);
                visited.push(false);
            }
        }
        return out;
    }
};