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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode *> Q;
        vector<int> out;
        Q.push(root);

        while(!Q.empty())
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                TreeNode *cur = Q.front();
                Q.pop();
                if(cur->left != nullptr)
                    Q.push(cur->left);
                if(cur->right != nullptr)
                    Q.push(cur->right);

                if(i == qSize-1)
                    out.push_back(cur->val);
            }
        }
        return out;
    }
};
