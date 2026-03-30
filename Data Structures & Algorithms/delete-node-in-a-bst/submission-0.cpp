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
    TreeNode* findMin(TreeNode* root)
    {
        if(root == nullptr) // Should not happen in this code flow
            return nullptr;
        
        if(root->left)
            return findMin(root->left);

        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // failed to find the key node
        if(root == nullptr)
            return root;
        
        if(key > root->val)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else // found the node
        {
            TreeNode *del = nullptr;
            // Case 1: node to be deleted is leaf or has only one child
            if(root->left == nullptr)
            {
                del = root;
                root = root->right;

            }
            else if(root->right == nullptr)
            {
                del = root;
                root = root->left;
            }
            else
            {
                // Case 2: node to be deleted has 2 children.
                // Find the inorder successor
                TreeNode *pred = findMin(root->right);
                root->val = pred->val;
                root->right = deleteNode(root->right, root->val);
            }
            if(del)
                delete del;            
        }

        return root; // Should not hit in case of node found
    }
};