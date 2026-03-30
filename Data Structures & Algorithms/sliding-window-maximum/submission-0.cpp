class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxHeap; // {val, idx}

        if(nums.size() <= k)
            return {*max_element(nums.begin(), nums.end())};
        
        vector<int> out;
        int l = 0;
        int r = 0;
        for(; r < k; ++r)
            maxHeap.push({nums[r], r});

        out.push_back(maxHeap.top().first);
        while(r < nums.size())
        {
            maxHeap.push({nums[r], r});
            l++;
            while(maxHeap.top().second < l)
                maxHeap.pop();
            out.push_back(maxHeap.top().first);
            r++;
        }
        return out;
    }
};
