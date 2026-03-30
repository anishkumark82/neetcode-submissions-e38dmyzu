struct hashFunc{
    size_t operator()(const pair<int,int> &p) const{
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1^h2;
    }
};
class Solution {
private:
    int _dfs(int i, int amount, vector<int>& coins, unordered_map<pair<int,int>, int, hashFunc> &memo)
    {
        if (amount == 0)
            return 1;
        
        if(amount < 0 || i == coins.size())
            return 0;

        if(memo.find({i, amount}) != memo.end())
            return memo[{i, amount}];

        // skip ith coin
        int count = _dfs(i+1, amount, coins, memo);

        // include ith coin
        count += _dfs(i, amount-coins[i], coins, memo);
        memo[{i, amount}] = count;
        return count;
    }
public:
    int change(int amount, vector<int>& coins) {
        unordered_map<pair<int,int>, int, hashFunc> memo;
        return _dfs(0, amount, coins, memo);
    }
};
