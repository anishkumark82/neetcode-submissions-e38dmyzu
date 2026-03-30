class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        for(auto &n : nums)
        {
            if(numSet.find(n-1) == numSet.end()) // left most element in a group
            {
                int curLen = 1;
                int i = n+1;
                while(numSet.find(i) != numSet.end())
                {
                    curLen++;
                    i++;
                }
                maxLen = max(maxLen, curLen);
            }
        } 
        return maxLen;
    }
};
