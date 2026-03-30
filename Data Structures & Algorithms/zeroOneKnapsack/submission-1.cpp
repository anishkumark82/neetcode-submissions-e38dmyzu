struct hashFunc{
public:
    size_t operator()(const pair<int,int> &p) const {
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1^h2;
    }
};
class Solution {
private:
// O(2^n) solution
    int _dfs(int i, vector<int> &profit, vector<int>& weight, int capacity, 
        unordered_map<pair<int,int>, int, hashFunc> &memo)
    {
        if(i == profit.size())
            return 0;
        
        if(memo.find({i, capacity}) != memo.end())
            return memo[{i, capacity}];

        int maxProfit = 0;
        // Path with current index included
        if(weight[i] <= capacity)
        {
             maxProfit = profit[i];
             maxProfit += _dfs(i+1, profit, weight, capacity-weight[i], memo);
        }
        // Path without including the current index
        memo[{i, capacity}] = max(maxProfit, _dfs(i+1, profit, weight, capacity, memo));
        return memo[{i, capacity}];
    }
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        unordered_map<pair<int, int>, int, hashFunc> memo;    
        return _dfs(0, profit, weight, capacity, memo);
    }
};
