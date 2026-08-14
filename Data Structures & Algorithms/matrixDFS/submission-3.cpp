class Solution {
public:
    int _dfs(vector<vector<int>>& grid, int r, int c, 
             int rMax, int cMax, vector<vector<bool>> &visited)
    {
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;
        if(!rInBounds || !cInBounds)
            return 0;

        if(visited[r][c] || grid[r][c] != 0)
            return 0;
        
        if(r == rMax-1 && c == cMax - 1)
            return 1;

        visited[r][c] = true;
        // 4 paths
        int count = 0;
        count += _dfs(grid, r-1, c, rMax, cMax, visited);
        count += _dfs(grid, r+1, c, rMax, cMax, visited);
        count += _dfs(grid, r, c-1, rMax, cMax, visited);
        count += _dfs(grid, r, c+1, rMax, cMax, visited);

        visited[r][c] = false;
        return count;
    }

    int countPaths(vector<vector<int>>& grid) {
        
        int rMax = grid.size();
        int cMax = grid[0].size();
        if(grid[0][0] == 1 || grid[rMax-1][cMax-1] == 1)
            return 0;

        vector<vector<bool>> visited(rMax, vector<bool>(cMax, false));
        return _dfs(grid, 0, 0, rMax, cMax, visited);
    }
};
