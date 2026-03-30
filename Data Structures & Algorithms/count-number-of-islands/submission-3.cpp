class Solution {
private:
    int _dfs(int r, int c, vector<vector<char>>& grid, 
             vector<vector<bool>> &visited)
    {
        bool rInBounds = r >= 0 && r < grid.size();
        bool cInBounds = c >= 0 && c < grid[0].size();

        if(!rInBounds || !cInBounds)
            return false;

        if(visited[r][c])
            return false;
        
        if(grid[r][c] == '0')
            return false;

        
        visited[r][c] = true;

        _dfs(r-1, c, grid, visited);
        _dfs(r, c-1, grid, visited);
        _dfs(r, c+1, grid, visited);
        _dfs(r+1, c, grid, visited);
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int nIslands = 0;
        for(auto r = 0; r < grid.size(); ++r)
            for(auto c = 0; c < grid[0].size(); ++c)
                if(_dfs(r, c, grid, visited))
                    nIslands++;
        return nIslands;
    }
};
