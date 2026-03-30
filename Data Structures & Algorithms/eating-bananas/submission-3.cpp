class Solution {
private:
    bool isRateValid(int i, vector<int>&piles, int h)
    {
        int hCount = 0;
        for(auto &p : piles)
        {
            hCount += ceil(static_cast<double>(p) / i);
            if(hCount > h)
                return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // assertion: h > piles.size()
        
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int result = -1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(isRateValid(mid, piles, h)) 
            {
                result = mid;
                high = mid-1;
            }
            else 
                low = mid+1;            
        }
        return result;

    }
};
