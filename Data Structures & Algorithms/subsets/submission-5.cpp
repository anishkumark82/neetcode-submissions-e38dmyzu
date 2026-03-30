class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>> &out, vector<int>&subset, int idx)
    {
        if(idx == nums.size())
        {
            out.push_back(subset);
            return;
        }

        // Path with adding current element
        subset.push_back(nums[idx]);
        dfs(nums, out, subset, idx+1);
        subset.pop_back();
        dfs(nums, out, subset, idx+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        
        //dfs(nums, out, subset, 0);
        out.push_back({});
        for(auto &n : nums)
        {
            int oSize = out.size();
            for(auto i = 0; i < oSize; ++i)
            {
                vector<int> subset = out[i];
                subset.push_back(n);
                out.push_back(subset);
            }
        }
        return out; 
    }
};
