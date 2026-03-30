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
        // It is guranteed that k < Tree.size()
        int cnt = 0;
        stack<TreeNode *> s;
        TreeNode *cur = root;

        while(cur != nullptr || !s.empty())
        {
            if(cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            else // cur == nullptr and !s.empty()
            {
                cur = s.top();
                s.pop();
                cnt++;
                if(cnt == k)
                    return cur->val;
                cur = cur->right;
            }
        }
        throw;
    }
};
