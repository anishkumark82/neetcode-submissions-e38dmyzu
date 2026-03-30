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
        vector<int> out;
        if(root == nullptr)
            return out;
        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty())
        {
            int lSize = Q.size();
            for(auto i = 0; i < lSize; ++i)
            {
                TreeNode* cur = Q.front();
                Q.pop();
                if(cur->left)
                    Q.push(cur->left);
                if(cur->right)
                    Q.push(cur->right);
                
                if(i == lSize-1)
                    out.push_back(cur->val);
            }
        }
        return out;

    }
};
