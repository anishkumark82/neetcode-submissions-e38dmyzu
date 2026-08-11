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
       
       // Iterative inorder DFS
        stack<TreeNode *> s;
        TreeNode *cur = root;
        int i = 0;
        while(cur != nullptr || !s.empty())
        {
            if(cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            else // !s.empty()
            {
                cur = s.top(); // already processed in cur if condition.
                s.pop();
                i++;
                if(i == k)
                    return cur->val;
                cur = cur->right; // check if there is the right node
            }
        }
        throw;
    }
};
