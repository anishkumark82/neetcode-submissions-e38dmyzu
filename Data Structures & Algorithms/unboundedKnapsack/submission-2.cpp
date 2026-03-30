using MAP_PAIR = pair<int,int>;
struct hashFunc{
    size_t operator()(const MAP_PAIR &p) const {
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1 ^ h2;
    }
};
class Solution {
    // O(2^C) -- Brute force backtracking
    // O(n*c) -- memoization
    // T --> O(n*c) --> S --> O(n*c) Tabulation
private:
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        vector<vector<int>> dp(profit.size(), vector<int>(capacity+1, 0));

        // init the first element
        for(auto c = 1; c <= capacity; ++c)
            if(weight[0] <= c)
                dp[0][c] = profit[0] + dp[0][c-weight[0]];
            
        for(auto r = 1; r < profit.size(); ++r)
            for(auto c = 1; c <= capacity; ++c)
            {
                int skip = dp[r-1][c];
                int include = 0;
                if(weight[r] <= c)
                    include = profit[r] + dp[r][c - weight[r]];
                dp[r][c] = max(include, skip);
            }
        return dp.back().back();
    }
};
