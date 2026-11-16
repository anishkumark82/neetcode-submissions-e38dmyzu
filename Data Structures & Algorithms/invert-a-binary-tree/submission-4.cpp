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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return root;

        queue<TreeNode *>Q;
        Q.push(root);

        while(!Q.empty())
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                TreeNode *cur = Q.front();
                Q.pop();
                if(cur->right)
                    Q.push(cur->right);
                if(cur->left)
                    Q.push(cur->left);
                //TreeNode *tmp = cur->right;
                //cur->right = cur->left;
                //cur->left = tmp;
                swap(cur->right, cur->left);
            }
        }
        return root;
    }
};
