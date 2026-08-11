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
    // [1,2,3,4]
    // [2,1,3,4]
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        TreeNode *root = nullptr;
        if(p.size() == 0)
            return root;
        
        root = new TreeNode(p[0]);
        vector<int> lp,li,rp,ri;
        int idx = 0;
        for(;idx < p.size() && p[0] != i[idx]; ++idx)
            li.push_back(i[idx]);
        // li [2]
        // lp [2]
        if(li.size() != 0)
            lp.insert(lp.end(), p.begin()+1, p.begin()+ 1 + li.size());
        
        // ri[3,4]
        // rp[3,4]
        if(idx + 1 < p.size()) // 2
        {
            ri.insert(ri.end(),i.begin()+idx+1, i.end());
            rp.insert(rp.end(), p.begin()+1+li.size(), p.end());
        }
        root->left = buildTree(lp, li);
        root->right = buildTree(rp, ri);
        return root;
    }
};
