class Solution {
    void dfs(unordered_map<int,int> &nMap, int n, vector<int> &cur, vector<vector<int>> &out)
    {
        if(n == 0)
        {
            out.push_back(cur);
            return;
        }

        for(auto &itr : nMap)
        {
            if(itr.second != 0)
            {
                cur.push_back(itr.first);
                itr.second--;
                dfs(nMap, n-1, cur, out);
                itr.second++;
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> nMap;
        for(auto &n : nums)
            nMap[n]++;
        
        vector<vector<int>> out;
        vector<int> cur;
        dfs(nMap, n, cur, out);
        return out;
    }
};