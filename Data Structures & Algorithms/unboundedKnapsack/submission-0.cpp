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
private:
    int _dfs(int i, vector<int>& profit, vector<int>& weight, 
             int capacity, unordered_map<MAP_PAIR, int, hashFunc> &memo)
    {
        if(i == profit.size())
            return 0;
        if(memo.find({i, capacity}) != memo.end())
            return memo[{i, capacity}];

        int maxProfit = _dfs(i+1, profit, weight, capacity, memo);
        if(capacity - weight[i] >= 0)
            maxProfit = max(maxProfit, profit[i] + _dfs(i, profit, weight, capacity-weight[i], memo));
        memo[{i, capacity}] = maxProfit;
        return maxProfit;
    }
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        unordered_map<MAP_PAIR, int, hashFunc> memo;
        return _dfs(0, profit, weight, capacity, memo);
    }
};
