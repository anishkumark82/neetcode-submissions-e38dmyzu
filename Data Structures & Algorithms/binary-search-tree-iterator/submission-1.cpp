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
private: 
public:
    void _trackInOrder()
    {
        while(cur != nullptr)
        {
            s.push(cur);
            cur = cur->left;
        }
    }
    BSTIterator(TreeNode* root) {
        cur = root;
        _trackInOrder();
    }
    
    int next() {
        // Hope will get only called if !s.empty()
        cur = s.top();
        s.pop();
        int ret = cur->val;
        cur = cur->right;
        _trackInOrder();
        return ret;
    }
    
    bool hasNext() {
        return (!s.empty());
    }
    TreeNode *cur{nullptr};
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */