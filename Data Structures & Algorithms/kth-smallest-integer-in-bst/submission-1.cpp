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
        TreeNode* cur = root;
        stack<TreeNode*> s;

        while(cur != nullptr || !s.empty())
        {
            while(cur != nullptr) // Keep going to the leftmost node
            {
                s.push(cur);
                cur = cur->left;
            }
            if(!s.empty()) // Now we are at the left most node .. Start poping
            {
                cur = s.top();
                s.pop();
                k--;
                if(k == 0)
                    return cur->val;
                cur = cur->right;
            }
        }
        return -1;
    }
};
