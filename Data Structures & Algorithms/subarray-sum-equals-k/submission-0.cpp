class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        int count = 0;
        unordered_map<int,int> pMap;
        pMap[0] = 1;

        for(auto &n : nums)
        {
            prefix += n;
            if(pMap.find(prefix - k) != pMap.end())
                count += pMap[prefix-k];
            pMap[prefix]++; 
        }
        return count;
    }
};