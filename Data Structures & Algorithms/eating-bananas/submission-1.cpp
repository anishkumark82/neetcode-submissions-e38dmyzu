class Solution {
    bool isCocoFinishPile(vector<int>&piles, long k, int h)
    {
        long long totalHrs = 0;
        for(auto &p : piles)
        {
            totalHrs += ceil(static_cast<double>(p) / k);
            if(totalHrs > h)
                return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Assumes piles.size() < h
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int minSize = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isCocoFinishPile(piles, mid, h))
            {
                minSize = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return minSize;
    }
};
