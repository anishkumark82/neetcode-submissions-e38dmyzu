class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 1)
            return 0;
            
        int p2 = 0;
        int p1 = 0;
        for(auto i = 2; i <= cost.size(); ++i)
        {
            int temp = p1;
            p1 = min(p2 + cost[i-2], p1 + cost[i-1]);
            p2 = temp;
        }
        return p1;
    }
};
