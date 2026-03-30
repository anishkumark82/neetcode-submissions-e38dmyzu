class Solution {
private:
    bool _dfs(vector<vector<char>> &grid, 
              int r, int c, 
              int rMax, int cMax, vector<vector<bool>> &visited)
    {
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;

        // Check location validity
        if(!rInBounds || !cInBounds)
            return false;

        // Is it already visited or is it water
        if(grid[r][c] == '0' || visited[r][c] == true)
            return false;
        
        visited[r][c] = true;

        // explore all the parts of the island
        bool explore = true;
        _dfs(grid, r-1, c, rMax, cMax, visited);
        _dfs(grid, r+1, c, rMax, cMax, visited);
        _dfs(grid, r, c-1, rMax, cMax, visited);
        _dfs(grid, r, c+1, rMax, cMax, visited);
                  
        return explore;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rMax = grid.size();
        int cMax = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(rMax, vector<bool>(cMax, false));
        for(auto r = 0; r < rMax; ++r)
            for(auto c = 0; c < cMax; ++c)
                if (_dfs(grid, r, c, rMax, cMax, visited) == true)
                    count++;    
        return count;
    }
};
