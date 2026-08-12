struct TreeNode{
    int key;
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int k, int v): key(k), val(v), left(nullptr), right(nullptr){}
};
class TreeMap {

public:
    TreeMap():root(nullptr) {
        
    }
    TreeNode* insertHelper(TreeNode *r, int key, int val)
    {
        if(r == nullptr)
            return new TreeNode(key, val);
        if(key == r->key)
            r->val = val;
        else if(key < r->key)
            r->left = insertHelper(r->left, key, val);
        else
            r->right = insertHelper(r->right, key, val);

        return r;
    }
    void insert(int key, int val) {
        root = insertHelper(root, key, val); 
    }

    int get(int key) {
        TreeNode *t = root;

        while(t != nullptr)
        {
            if(key < t->key)
                t = t->left;
            else if(key > t->key)
                t = t->right;
            else
                return t->val;
        }
        return -1;
    }

    int getMin() {
        TreeNode *t = root;
        while(t && t->left)
            t = t->left;
        return (t) ? t->val : -1;
    }

    int getMax() {
        TreeNode *t = root;
        while(t && t->right)
            t = t->right;
        return (t) ? t->val : -1;
    }

    void findMin(TreeNode *t, int &k, int &v)
    {
        while(t && t->left)
            t = t->left;
        k = t->key;
        v = t->val;
    }

    TreeNode* removeHelper(TreeNode *r, int key)
    {
        if(r == nullptr)
            return nullptr;
        
        if(key < r->key)
            r->left = removeHelper(r->left, key);
        else if(key > r->key)
            r->right = removeHelper(r->right, key);
        else
        {
            // case 1 & 2 : left and right nullptr or left or right nullptr
            TreeNode *tmp = r;
            if(r->left == nullptr)
            {
                r = r->right;
                delete tmp;
            }
            else if(r->right == nullptr)
            {
                r = r->left;
                delete tmp;
            }
            else
            {
                int mKey = -1;
                int mVal = -1;
                findMin(r->right, mKey, mVal);
                r->key = mKey;
                r->val = mVal;
                r->right = removeHelper(r->right, mKey);
            }
        }
        return r;
    }
    void remove(int key) {
        root = removeHelper(root, key);
    }

    std::vector<int> getInorderKeys() {
        if(root == nullptr)
            return {};
        stack<TreeNode *>s;
        vector<int> out;
        TreeNode *cur = root;
        while(cur || !s.empty())
        {
            if(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            else // if (!s.empty())
            {
                cur = s.top();
                out.push_back(cur->key);
                s.pop();
                cur = cur->right;
            }
        }
        return out;
    }
    TreeNode *root;
};
