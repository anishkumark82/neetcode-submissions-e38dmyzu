class Solution {
private:
    bool _dfs(int i, int gasRem, vector<int>& gas, vector<int>& cost, unordered_set<int>& visited)
    {
        if(visited.count(i))
            return true;
        
        visited.insert(i);

        gasRem += (gas[i] - cost[i]);
        if(gasRem < 0)
            return false;
        
        return _dfs((i+1) % gas.size(), gasRem, gas, cost, visited);
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(auto i = 0; i < gas.size(); ++i)
        {
            unordered_set<int> visited;
            if(_dfs(i, 0, gas, cost, visited))
                return i;
        }
        return -1;
    }
};
