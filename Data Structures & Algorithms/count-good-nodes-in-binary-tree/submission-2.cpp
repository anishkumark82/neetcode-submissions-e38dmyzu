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
    int goodNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;

        //NLR
        int cnt = 0;
        stack<pair<TreeNode*, int>> s;
        stack<bool> visited;

        s.push({root, -101});
        visited.push(false);
        while(!s.empty())
        {
            auto [cur, maxVal] = s.top();
            auto V = visited.top();
            s.pop();
            visited.pop();
            if(cur != nullptr && !V) // only consider not visited nodes
            {
                if(cur->val >= maxVal)
                    cnt++;
                
                s.push({cur, maxVal});
                visited.push(true);

                int val = max(cur->val, maxVal);
                s.push({cur->right, val});
                visited.push(false);
                s.push({cur->left, val});
                visited.push(false);
            }
        }
        return cnt;

    }
};
