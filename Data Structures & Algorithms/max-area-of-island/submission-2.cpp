class Solution {
public:
    int _dfs(vector<vector<int>> &grid, int r, int c, int rMax, int cMax)
    {
        // check validity of the r,c
        bool rInBounds = r >=0 && r < rMax;
        bool cInBounds = c >=0 && c < cMax;

        if(!rInBounds || !cInBounds)
            return 0;
        
        if(grid[r][c] != 1)
            return 0;
        
        grid[r][c] = -1;

        int area = 1;
        area += _dfs(grid, r-1, c, rMax, cMax);
        area += _dfs(grid, r+1, c, rMax, cMax);
        area += _dfs(grid, r, c-1, rMax, cMax);
        area += _dfs(grid, r, c+1, rMax, cMax);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rMax = grid.size();
        int cMax = grid[0].size();
        int maxArea = 0;

        for(auto r = 0; r < rMax; ++r)
            for(auto c = 0; c < cMax; ++c)
                maxArea = max(_dfs(grid, r, c, rMax, cMax), maxArea);

        return maxArea;
    }
};
