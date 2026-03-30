class Solution {
private:
    void _dfs(vector<int> &nums, int start, int sum, vector<int> &cur, vector<vector<int>> &out)
    {
        if(sum == target)
        {
            out.push_back(cur);
            return;
        }
        if(sum > target)
            return;

        for(auto i = start; i < nums.size(); ++i)
        {
            sum += nums[i];
            cur.push_back(nums[i]);
            _dfs(nums, i, sum, cur, out);
            sum -= nums[i];
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>> out;
        int sum = 0;
        this->target = target;
        _dfs(nums, 0, sum, cur, out);    
        return out;
    }
    int target;
};
