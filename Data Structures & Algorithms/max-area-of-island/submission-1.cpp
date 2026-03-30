class Solution {
private:
    int _explore(vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &visited)
    {
        bool rInBounds = r >= 0 && r < grid.size();
        bool cInBounds = c >= 0 && c < grid[0].size();

        if(!rInBounds || !cInBounds || visited[r][c])
            return 0;
        
        if(grid[r][c] == 0)
            return 0;

        visited[r][c] = true;
        int area = 1;
        area += _explore(grid, r+1, c, visited);
        area += _explore(grid, r-1, c, visited);
        area += _explore(grid, r, c+1, visited);
        area += _explore(grid, r, c-1, visited);

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(auto r = 0; r < grid.size(); ++r)
            for(auto c = 0; c < grid[0].size(); ++c)
                maxArea = max(maxArea, _explore(grid, r, c, visited));
        return maxArea;
    }
};
