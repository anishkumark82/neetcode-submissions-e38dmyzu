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

public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0)
            return nullptr;
        
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        
        // identify the left and right subtrees recursively
        auto midItr = std::find(inorder.begin(), inorder.end(), rootVal);
        int mid = std::distance(inorder.begin(), midItr);

        vector<int> inorderLeft(inorder.begin(), inorder.begin()+mid);
        vector<int> inorderRight(inorder.begin()+mid+1, inorder.end());
        vector<int> preorderLeft(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> preorderRight(preorder.begin()+mid+1, preorder.end());;

        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);
        return root;
    }
};
