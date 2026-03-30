class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        int maxLen = 1;
        unordered_set<int> numSet(nums.begin(), nums.end());
        // Determine the left most element in a sequence
        for(auto itr = numSet.begin(); itr != numSet.end(); ++itr)
        {
            auto n = *itr;
            int curLen = 1;
            if (numSet.find(n-1) != numSet.end())
                continue;
            int m = n+1;
            while(numSet.find(m) != numSet.end())
            {
                curLen++;
                maxLen = max(curLen, maxLen);
                m++;
            }
        }
        return maxLen;
    }
};
