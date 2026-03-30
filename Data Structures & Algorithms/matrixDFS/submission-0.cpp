class Solution {
private:
    int _dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>> &visited)
    {
        bool rInBounds = r >= 0 && r < grid.size();
        bool cInBounds = c >= 0 && c < grid[0].size();

        if(!rInBounds || !cInBounds || visited[r][c])
            return 0;

        if(grid[r][c] != 0) // Node already visited in the current path (cycle)
            return 0;

        if (r == grid.size() - 1 && c == grid[0].size() - 1) // reached the destination point
            return 1;

        visited[r][c] = true;

        int paths = _dfs(grid, r+1, c, visited); // [0,0] 0 // [0,1] 0 
        paths += _dfs(grid, r-1, c, visited); // [0,0] 0 // 
        paths += _dfs(grid, r, c+1, visited); // [0,0]
        paths += _dfs(grid, r, c-1, visited);

        visited[r][c] = false;
        return paths;
    }
public:
    
    int countPaths(vector<vector<int>>& grid) {
        // 4 degrees of freedom
        // 0s forms the path -- 1s form obstucle
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        return _dfs(grid, 0, 0, visited);
    }
};
