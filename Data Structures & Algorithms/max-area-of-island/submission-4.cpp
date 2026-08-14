class Solution {
private:
    int _explore(vector<vector<int>> &grid, int r, int c, int rMax, int cMax, 
                 vector<vector<bool>> &visited)
    {
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;

        if(!rInBounds || !cInBounds)
            return 0;
        
        if(grid[r][c] == 0 || visited[r][c])
            return 0;
        
        visited[r][c] = true;
        int area = 1;
        area += _explore(grid, r-1, c, rMax, cMax, visited);
        area += _explore(grid, r+1, c, rMax, cMax, visited);
        area += _explore(grid, r, c-1, rMax, cMax, visited);
        area += _explore(grid, r, c+1, rMax, cMax, visited);

        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rMax = grid.size();
        int cMax = grid[0].size();
        int maxArea = 0;
        vector<vector<bool>> visited(rMax, vector<bool>(cMax, false));
        for(auto r = 0; r < rMax; ++r)
            for(auto c = 0; c < cMax; ++c)
                maxArea = max(maxArea, _explore(grid, r, c, rMax, cMax, visited));
        
        return maxArea;
    }
};
