class hashFunc{
public:
    size_t operator()(const pair<int,int> &p) const{
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1^h2;
    }
};
class Solution {
private:
    int _dfs(int i, vector<int> &d, vector<int> &c, vector<int> &dp)
    {
        if(i >= d.size()) // Will ensure the costs are not exhausted
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        // 3 paths
        // 1. take daily pass
        int minCost = c[0] + _dfs(i+1, d, c, dp);

        // 2. weekly pass from that day
        int newI = i;
        while(d[newI] < d[i] + 7 && newI < d.size())
            newI++;

        minCost = min(minCost, c[1] + _dfs(newI, d, c, dp));

        // 2. monthly pass from that day
        newI = i;
        while(d[newI] < d[i] + 30 && newI < d.size())
            newI++;

        minCost = min(minCost, c[2] + _dfs(newI, d, c, dp));
        dp[i] = minCost;
        return minCost;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return _dfs(0, days, costs, dp);
    }
};