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
        vector<int> out;
        stack<TreeNode *> s;
        stack<bool> V;
        s.push(root);
        V.push(false);
        while(!s.empty())
        {
            TreeNode *cur = s.top();
            bool visited = V.top();
            s.pop();
            V.pop();

            if(cur)
            {
                if(visited)
                    out.push_back(cur->val);
                else
                {
                    s.push(cur);
                    V.push(true);
                    s.push(cur->right);
                    V.push(false);
                    s.push(cur->left);
                    V.push(false);
                }
            }
            // else do nothing
        }
        return out;
    }
};