class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>> &out, int idx)
    {
        if(idx == nums.size())
        {
            out.push_back({});
            return;
        }

        dfs(nums, out, idx+1);
        for(auto &e : out)
        {
            vector<int> cur = e;
            cur.push_back(nums[idx]);
            out.push_back(cur);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        dfs(nums, out, 0);
        return out; 
    }
};
