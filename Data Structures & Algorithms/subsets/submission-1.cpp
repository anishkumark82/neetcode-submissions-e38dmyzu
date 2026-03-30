class Solution {
public:
    void findSubSets(vector<int>& nums, int i, vector<int> &cur, vector<vector<int>> &out)
    {
        if(i == nums.size())
        {
            out.push_back(cur);
            return;
        }
        
        cur.push_back(nums[i]);
        findSubSets(nums, i+1, cur, out);
        cur.pop_back();
        findSubSets(nums, i+1, cur, out);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> cur;
        findSubSets(nums, 0, cur, out);
        return out;
    }
};
