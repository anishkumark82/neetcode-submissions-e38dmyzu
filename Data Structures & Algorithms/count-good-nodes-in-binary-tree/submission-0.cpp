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
private:
    int goodHelper(TreeNode* root, int curMax)
    {
        if(root == nullptr)
            return 0;

        int cnt = 0; 
        if(curMax <= root->val)
        {
            cnt++;
            curMax = root->val;
        }
        
        cnt += goodHelper(root->left, curMax) + goodHelper(root->right, curMax);
        return cnt;

    }
public:

    int goodNodes(TreeNode* root) {
        return goodHelper(root, -101);
    }
};
