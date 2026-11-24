class Solution {

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res{{}};

        for(auto &n : nums)
        {
            vector<vector<int>> tmp;
            for(auto &curE : res)
            {
                for(auto i = 0; i < curE.size()+1; ++i)
                {
                    vector<int> t2 = curE;
                    t2.insert(t2.begin()+i, n);
                    tmp.push_back(t2);
                }
            }
            res = tmp;
        }    
        return res;
    }
};
