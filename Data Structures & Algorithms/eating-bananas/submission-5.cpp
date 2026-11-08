// piles.size() <= h
//[2, 4,    3,      2   5] - 10
// 2. 3. 1. 3. 2. 3 2
// 2. 2. 2  2 1.   2. 2 2 1  
//  
// 1    2   3   4   5
//          m
//     l h                  
//   
class Solution {
private:
    bool doesKokoFinish(vector<int>& piles, int h, int v)
    {
        int totHrs = 0;
        for(auto &p : piles)
        {
            totHrs += ceil(static_cast<double>(p) / v);
            if(totHrs > h)
                return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size() > h)
            return -1; // not possible to finish in h hours
        int maxB = *max_element(piles.begin(), piles.end());
        if(piles.size() == h)
            return maxB;
        
        int low = 1;
        int high = maxB;
        int ret = -1;
        while(low <= high)
        {
            int mid = low + (high-low) / 2;
            
            if (doesKokoFinish(piles, h, mid))
            {
                ret = mid;
                high = mid-1;
            }
            else
                low = mid+1;    
        }
        return ret;        
    }
};
