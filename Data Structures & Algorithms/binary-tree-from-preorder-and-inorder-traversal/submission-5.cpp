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
    TreeNode* buildTreeHlper(vector<int>&p, int s1, int e1, vector<int>&i, int s2, int e2)
    {
        TreeNode *root = nullptr;
        if(s1 > e1)
            return root;
        
        root = new TreeNode(p[s1]);
        int pivot = iMap[root->val];
        int lSize = pivot - s2; 
        root->left = buildTreeHlper(p,s1+1, s1+lSize, i, s2, pivot-1); 
        root->right = buildTreeHlper(p, s1+lSize+1, e1, i, pivot+1, e2);
        return root;
    } 
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        iMap.clear();

        for(auto k = 0; k < i.size(); ++k)
            iMap[i[k]] = k;
        
        return buildTreeHlper(p, 0, (int)p.size()-1, i, 0, (int)i.size()-1);
    }
    unordered_map<int,int> iMap;
};
