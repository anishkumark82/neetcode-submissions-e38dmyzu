class Solution {
private:

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // iterative solution
        
        vector<vector<int>> out = {{}};
        for(auto &n : nums)
        {
            vector<vector<int>> curOut; 
            for(auto &v : out)
            {
                for(auto i = 0; i < v.size()+1; ++i)
                {
                    vector<int> t = v;
                    t.insert(t.begin()+i, n);
                    curOut.push_back(t);
                }
            }
            out = curOut;
        }
        return out;
    }
};
