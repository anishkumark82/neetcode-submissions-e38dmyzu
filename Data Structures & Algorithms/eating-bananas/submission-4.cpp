class Solution {
    bool canFinish(vector<int>&piles, int x, int h)
    {
        int total = 0;
        for(auto &p : piles)
        {
            total += ceil(static_cast<double>(p)/x);
            if(total > h)
                return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        if(piles.size() > h)
            return -1;

        // Koko can eat between 1 and max_element(piles) 
        // Do binary search and find the minEatingSpeed
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int result = e;
        while(s <= e)
        {
            int m = s + (e-s)/2;
            if(canFinish(piles, m, h))
            {
                result = m;
                e = m-1;
            }
            else
                s = m+1;
        }
        return result;
    }
};
