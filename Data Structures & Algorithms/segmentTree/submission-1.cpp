struct TreeNode{
    int L; // Denotes array index for the range sum
    int R; // Denote array index for the range sum
    int sum;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int iL, int iR, int total = 0):L(iL), R(iR), sum(total), left(nullptr), right(nullptr){}
};

// ["SegmentTree", [1 2 3 4 5], "query", 0, 2, "query", 2, 4, "update", 3, 0, "query", 2, 4]
class SegmentTree {
private:
    TreeNode* build(vector<int> &nums, int L, int R)
    {
        TreeNode *root = new TreeNode(L, R, 0);
        if(L == R) // Reached the leaf
            root->sum = nums[L];
        else
        {
            int M = (L + R) / 2;
            root->left = build(nums, L, M);
            root->right = build(nums, M+1, R);
            root->sum = root->left->sum + root->right->sum;
        }
        return root;
    }

    void _update(TreeNode *root, int idx, int val)
    {
        if(root->L == idx && root->R == idx)
        {
            root->sum = val;
            return;
        }
        
        int M = (root->L + root->R) / 2;
        if(idx <= M)
            _update(root->left, idx, val);
        else
            _update(root->right, idx, val);
        
        root->sum = root->left->sum + root->right->sum;
    }
// ["SegmentTree", [1 2 3 4 5], "query", 0, 2, "query", 2, 4, "update", 3, 0, "query", 2, 4]
    int _query(TreeNode *root, int L, int R)
    {
        if(L == root->L && R == root->R)
            return root->sum;
        
        int M = (root->L + root->R) / 2;
        if(R <= M)
            return _query(root->left, L, R);
        else if(L > M)
            return _query(root->right, L, R);
        
        return _query(root->left, L, M) + _query(root->right, M+1, R);
    }
public:
    SegmentTree(vector<int>& nums) {
        nSize = nums.size();
        mRoot = build(nums, 0, nSize-1);
    }
    
    void update(int index, int val) {
        if(index >= nSize)
            return;

        _update(mRoot, index, val);
    }
    
    int query(int L, int R) {
        bool LInBounds = L >= 0 && L < nSize;
        bool RInBounds = R >= 0 && R < nSize;
        
        if(!LInBounds && !RInBounds)
            return -1;
        
        return _query(mRoot, L, R);
    }
    TreeNode *mRoot;
    int nSize;
};
