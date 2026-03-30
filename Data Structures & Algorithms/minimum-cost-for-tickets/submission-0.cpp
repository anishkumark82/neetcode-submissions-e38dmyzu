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
    int _dfs(int i, int curCost, vector<int> &d, vector<int> &c, 
            unordered_map<pair<int,int>, int, hashFunc> &dp)
    {
        if(i >= d.size()) // Will ensure the costs are not exhausted
            return curCost;
        
        if(dp.find({i, curCost}) != dp.end())
            return dp[{i, curCost}];

        // 3 paths
        // 1. take daily pass
        int minCost = _dfs(i+1, c[0]+curCost,d, c, dp);

        // 2. weekly pass from that day
        int newI = i;
        while(d[newI] < d[i] + 7 && newI < d.size())
            newI++;

        minCost = min(minCost, _dfs(newI, c[1] + curCost, d, c, dp));

        // 2. monthly pass from that day
        newI = i;
        while(d[newI] < d[i] + 30 && newI < d.size())
            newI++;

        minCost = min(minCost, _dfs(newI, c[2] + curCost, d, c, dp));
        dp[{i,curCost}] = minCost;

        return minCost;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<pair<int,int>, int, hashFunc> dp;
        return _dfs(0, 0, days, costs, dp);
    }
};