class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int maxLen = 1;
        unordered_set<int> numSet{nums.begin(), nums.end()};

        for(auto &n : nums)
        {
            int curLen = 1;
            if(numSet.count(n+1)) // Is this the rightmost number 
                continue;
            int m = n-1;
            while(numSet.count(m))
            {
                curLen++;
                maxLen = max(curLen, maxLen);
                m--;
            }
        }
        return maxLen;
    }
};
