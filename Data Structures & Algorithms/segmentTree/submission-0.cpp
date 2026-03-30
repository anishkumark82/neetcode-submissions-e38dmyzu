struct SegmentNode{
    int sum;
    int L;
    int R;
    SegmentNode *left;
    SegmentNode *right;

    SegmentNode(int total, int l, int r): sum(total), L(l), R(r), left(nullptr), right(nullptr){};
};
class SegmentTree {
private:
    int _buildSegTree(SegmentNode *root)
    {
        if(root->L == root->R)
        {
            root->sum = mNum[root->L];
            return root->sum;
        }   
        // Find Mid
        int mid = (root->L + root->R)/2;
        root->left = new SegmentNode(0, root->L, mid);
        root->right = new SegmentNode(0, mid+1, root->R);
        root->sum = _buildSegTree(root->left) + _buildSegTree(root->right);
        return root->sum;
    }
    int _updateSegTree(SegmentNode *root, int index, int value)
    {
        if(root->L == index && root->R == index)
        {
            root->sum = value;
            return root->sum;
        }
        // Find mid
        int mid = (root->L + root->R) / 2;
        if(index > mid)
            root->sum = _updateSegTree(root->right, index, value) + root->left->sum;
        else
            root->sum = _updateSegTree(root->left, index, value) + root->right->sum;
        return root->sum;
    }
    int _queryHelper(SegmentNode *root, int L, int R)
    {
        // Check if L, R is too left of root or too right of root
        if(R < root->L || L > root->R)
            return 0;
        
        // root is within L, R
        if(L <= root->L && root->R <= R)
            return root->sum;
        
        // It is spread across both sides
        return _queryHelper(root->left, L, R) + _queryHelper(root->right, L, R);
    }
public:

    SegmentTree(vector<int>& nums) {
        mNum = nums;
        head = new SegmentNode(0, 0, nums.size()-1);
        _buildSegTree(head);
    }
    
    void update(int index, int val) {
        _updateSegTree(head, index, val);
    }
    
    int query(int L, int R) {
        return _queryHelper(head, L, R);
    }

    SegmentNode *head;
    vector<int> mNum;
};
