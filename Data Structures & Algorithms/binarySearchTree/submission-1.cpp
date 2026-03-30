class TreeNode{
public:
    int key;
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int k, int v, TreeNode* l = nullptr, TreeNode* r = nullptr): key(k), val(v), left(l), right(r){}
};
class TreeMap {

private:
    TreeNode* insertNode(TreeNode* r, int key, int val)
    {
        if(r == nullptr)
            return new TreeNode(key, val);
        
        if(key > r->key)
            r->right = insertNode(r->right, key, val);
        else if(key < r->key)
            r->left = insertNode(r->left, key, val);
        else
            r->val = val;
        return r;     
            
    }
    TreeNode* findMax(TreeNode* r)
    {
        if(r == nullptr)
            return nullptr;
        
        while(r->right)
            r = r->right;
        return r;
    }

    TreeNode* findMin(TreeNode* r)
    {
        if(r == nullptr)
            return nullptr;
        
        while(r->left)
            r = r->left;
        return r;
    }
    TreeNode* deleteNode(TreeNode *r, int key)
    {
        if(r == nullptr)
            return nullptr;
        
        if(key > r->key)
            r->right = deleteNode(r->right, key);
        else if(key < r->key)
            r->left = deleteNode(r->left, key);
        else
        {
            TreeNode *del = r;
            if(r->left == nullptr)
            {
                r = r->right;
                delete del;
            }
            else if(r->right == nullptr)
            {
                r = r->left;
                delete del;
            }
            else // both left and right != nullptr 
            {
                TreeNode *successor = findMin(root->right);
                r->key = successor->key;
                r->val = successor->val;
                r->right = deleteNode(r->right, successor->key);
            }
        }
        return r;
    }
    void inorder(TreeNode *r, vector<int> &out)
    {
        if(r == nullptr)
            return;
        
        inorder(r->left, out);
        out.push_back(r->key);
        inorder(r->right, out);
    }
public:
    TreeMap() {
        root = nullptr;
    }


    void insert(int key, int val) {
        root = insertNode(root, key, val);
    }

    int get(int key) {
        TreeNode *r = root;
        while(r)
        {
            if(key > r->key)
                r = r->right;
            else if (key < r->key)
                r = r->left;
            else
                return r->val;
        }
        return -1;
    }

    int getMin() {
        TreeNode *r = findMin(root);
        return (r == nullptr) ? -1 : r->val; 
    }

    int getMax() {
        TreeNode *r = findMax(root);
        return (root == nullptr) ? -1 : r->val;
            return -1;
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }


    std::vector<int> getInorderKeys() {
        vector<int> out;
        inorder(root, out);
        return out;
    }
    private:
        TreeNode* root;
};
