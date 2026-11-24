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
        // Iterative Inorder traversal
        stack<TreeNode *> s;
        TreeNode *cur = root;
        int cnt = 0;
        while(cur != nullptr || !s.empty())
        {
            if(cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            else // no more left element and time to pop the stack
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
