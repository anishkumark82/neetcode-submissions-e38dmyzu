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

/*

         3
        / \
       /   \
      /     \
     9      20
    / \       \
   15  7      25
   preorder = [3,9,15,7,20,25]
   inorder  = [15,9,7,3,20,25]

    3
    lpreOrder [9,15,7] linOrder [15,9,7]
    rpreOrder [20,25]  rinOrder [20,25 ]            
    
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size() == 0 || inorder.size() == 0)
            return nullptr;

        int rootVal = preorder[0];
        TreeNode *root = new TreeNode(rootVal); //val 1
        int inNode = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin(); // Will give the index 1
        vector<int> lPreorder(preorder.begin()+1, preorder.begin()+ 1 + inNode); //[2]
        vector<int> lInorder(inorder.begin(), inorder.begin()+inNode);    //[2]
        vector<int> rPreorder(preorder.begin()+inNode+1, preorder.end()); //[3,4]
        vector<int> rInorder(inorder.begin()+inNode+1, inorder.end());    //[3,4]
        

        root->left = buildTree(lPreorder, lInorder); //[2][2]
        root->right = buildTree(rPreorder, rInorder);
        return root;
    }
};
