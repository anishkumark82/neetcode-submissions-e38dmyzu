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
    TreeNode* builder(vector<int>& preorder, vector<int>& inorder, 
                      int pStart, int pEnd, int iStart, int iEnd)
    {
        if(pStart > pEnd)
            return nullptr;
        
        int n = preorder[pStart];
        int iIdx = iMap[n];
        TreeNode * root = new TreeNode(n);
        int pLeftEnd = pStart + iIdx - iStart;
        int pRightStart = pLeftEnd+1;
        // Left subtree 
        root->left = builder(preorder, inorder, pStart+1, pLeftEnd, iStart, iIdx-1);

        // right subtree
        root->right = builder(preorder, inorder, pRightStart, pEnd, iIdx+1, iEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(auto i = 0; i < inorder.size(); ++i)
            iMap[inorder[i]] = i;
        return builder(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);    
    }
private:
    unordered_map<int,int> iMap;
};
