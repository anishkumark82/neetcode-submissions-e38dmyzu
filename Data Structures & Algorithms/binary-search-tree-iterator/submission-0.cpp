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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        while(cur != nullptr)
        {
            s.push(cur);
            cur = cur->left;
        }

        cur = s.top();
        s.pop();
        int val = cur->val;
        cur = cur->right;
        return val;
    }
    
    bool hasNext() {
        return (cur || !s.empty());
    }
    stack<TreeNode *> s;
    TreeNode *cur;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */