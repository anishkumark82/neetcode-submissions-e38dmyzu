class Solution {
private:
    void helper(vector<int> &nums, int i, vector<int> &cur, vector<vector<int>> &out)
    {
        if(i == nums.size())
        {
            out.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        helper(nums, i+1, cur, out);
        cur.pop_back();
        while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        helper(nums, i+1, cur, out);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> out;
        vector<int> cur;
        helper(nums, 0, cur, out);
        return out;
    }
};
