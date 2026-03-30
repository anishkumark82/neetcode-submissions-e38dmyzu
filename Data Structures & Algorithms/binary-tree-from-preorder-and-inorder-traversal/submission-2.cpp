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
    int findIdx(vector<int> &v, int x)
    {
        return find(v.begin(), v.end(), x) - v.begin();
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()== 0 || inorder.size() == 0)
            return nullptr;
        
        int rNode = preorder[0]; 
        TreeNode *root = new TreeNode(rNode);
        // Find the rNode location in inorder
        int rootIdx = findIdx(inorder, rNode);
        
        
        vector<int>lpreorder(preorder.begin()+1, preorder.begin()+1+rootIdx);
        vector<int>rpreorder(preorder.begin()+1+rootIdx, preorder.end());
        vector<int>linorder(inorder.begin(), inorder.begin()+rootIdx);
        vector<int>rinorder(inorder.begin()+rootIdx+1, inorder.end());

        root->left = buildTree(lpreorder, linorder);
        root->right = buildTree(rpreorder, rinorder);
        return root;
    }
};
