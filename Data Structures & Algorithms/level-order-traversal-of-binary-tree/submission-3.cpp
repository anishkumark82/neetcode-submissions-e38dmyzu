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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<vector<int>> out;
        queue<TreeNode *> Q;
        Q.push(root);

        while(!Q.empty())
        {
            out.push_back({});
            auto &v = out.back();
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                TreeNode *cur = Q.front();
                Q.pop();
                v.push_back(cur->val);
                if(cur->left)
                    Q.push(cur->left);
                if(cur->right)
                    Q.push(cur->right);
            }
        }
        return out;
    }
};
