class Solution {
private:
    bool canFinishBananas(vector<int>& piles, int rate, int hrs)
    {
        int totalHrs = 0;
        for(auto p : piles) //O(n)
        {
            int t = (p/rate) + ((p % rate != 0)?1:0);
            totalHrs += t;
            
            if(totalHrs > hrs)
                return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *std::max_element(piles.begin(), piles.end()); // O(n)
        int result = -1;
        
        while(s <= e) //O(n log k)
        {
            int mid = (s + e) / 2;

            if(canFinishBananas(piles, mid, h)) // Can we further reduce bananas per hr
            {
                result = mid;
                e = mid-1;
            }
            else  // Cannot finish within the given ours. Try to increase number of bananas per hr
                s = mid+1;
        }
        return result;
    }
};
