class Solution {
private:
    int _dfs(vector<vector<int>> &grid, 
             int r, int c, 
             int rMax, int cMax, 
             vector<vector<bool>> &visited)
    {
        // Validity check
        bool rInBounds = r >=0 && r < rMax;
        bool cInBounds = c >=0 && c < cMax;
        if(!rInBounds || !cInBounds)
            return 0;

        // Invalid grid position for current path        
        if(grid[r][c] == 1 || visited[r][c])
            return 0;

        // Did we reach the destination ??
        if(r == rMax-1 && c == cMax-1)
            return 1;

        visited[r][c] = true;
        // 4 degrees of freedom
        int paths = 0;
        paths += _dfs(grid, r-1, c, rMax, cMax, visited);
        paths += _dfs(grid, r+1, c, rMax, cMax, visited);
        paths += _dfs(grid, r, c-1, rMax, cMax, visited);
        paths += _dfs(grid, r, c+1, rMax, cMax, visited);

        visited[r][c] = false;
        return paths;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int rMax = grid.size();
        int cMax = grid[0].size();
        vector<vector<bool>> visited(rMax, vector<bool>(cMax, false));
        return _dfs(grid, 0, 0, rMax, cMax, visited);
    }
};
