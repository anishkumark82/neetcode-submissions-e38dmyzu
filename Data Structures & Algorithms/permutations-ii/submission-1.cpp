class Solution {
    void _dfs(unordered_map<int,int> &cnt, int i, int n, vector<int> &cur, vector<vector<int>> &out)
    {
        if(i == n)
        {
            out.push_back(cur);
            return;
        }

        for(auto &itr : cnt)
        {
            if(itr.second != 0)
            {
                cur.push_back(itr.first);
                itr.second--;
                _dfs(cnt, i+1, n, cur, out);
                itr.second++;
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> nCnt;
        for(auto &n : nums)
            nCnt[n]++;
        vector<vector<int>> out;
        vector<int> cur{};
        _dfs(nCnt, 0, nums.size(), cur, out);
        return out;
    }
};