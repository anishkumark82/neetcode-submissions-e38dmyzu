class Solution {
private:
    vector<vector<int>> nbrs = {{-1, 0}, {+1, 0}, {0,-1}, {0,+1}};
    bool _dfs(vector<vector<char>> &grid, int r, int c, 
              int rMax, int cMax, 
              vector<vector<bool>> &visited) 
    {
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;
        if(!rInBounds || !cInBounds)
            return false;
        
        if(visited[r][c]) // Already considered part of the island
            return false;
        
        if(grid[r][c] != '1') // its an island part which is not visited
            return false;
        
        visited[r][c] = true;

        // also find all neigbors which are part of the island
        for(auto &n : nbrs)
            _dfs(grid, r+n[0], c+n[1], rMax, cMax, visited);
        
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rMax = grid.size();
        int cMax = grid[0].size();
        vector<vector<bool>> visited(rMax,vector<bool>(cMax, false));
        int cnt = 0;
        for(auto r = 0; r < rMax; ++r)
            for(auto c = 0; c < cMax; ++c)
                if((grid[r][c] != '0') && 
                    _dfs(grid, r, c, rMax, cMax, visited))
                    cnt++;
        return cnt;
                
    }
};
