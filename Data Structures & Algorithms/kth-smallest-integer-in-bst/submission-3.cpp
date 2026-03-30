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
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        stack<TreeNode *> s;
        TreeNode *cur = root;

        while(!s.empty() || cur != nullptr)
        {
            if(cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            else if(!s.empty())
            {
                cur = s.top();
                s.pop();
                n++;
                if(n == k)
                    return cur->val;
                cur = cur->right;
            }
        }
        return -1;
    }
};
