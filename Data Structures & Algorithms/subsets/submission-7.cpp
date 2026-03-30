class Solution {
private:
    void helper(vector<int> &nums, int i, vector<int> &cur, vector<vector<int>> &out)
    {
        if(i == nums.size()) // came to the end of the array
        {
            out.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        helper(nums, i+1, cur, out);
        cur.pop_back();
        helper(nums, i+1, cur, out);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> cur;

        helper(nums, 0, cur, out);
        return out;        
    }
};
