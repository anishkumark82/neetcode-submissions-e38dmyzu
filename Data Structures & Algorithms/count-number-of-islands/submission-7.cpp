class Solution {
public:
    bool _explore(vector<vector<char>> &grid, int r, int c, 
                  int rMax, int cMax, 
                  vector<vector<bool>> &visited)
    {
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;

        if (!rInBounds || !cInBounds)
            return false;

        if(grid[r][c] != '1' || visited[r][c])
            return false;
        
        visited[r][c] = true;
        bool status = true;
        _explore(grid, r-1, c, rMax, cMax, visited);
        _explore(grid, r+1, c, rMax, cMax, visited);
        _explore(grid, r, c-1, rMax, cMax, visited);
        _explore(grid, r, c+1, rMax, cMax, visited);

        return status;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rMax = grid.size();
        int cMax = grid[0].size();
        vector<vector<bool>> visited(rMax, vector<bool>(cMax, false));
        int count = 0;

        for(auto r = 0; r < rMax; ++r)
            for(auto c = 0; c < cMax; ++c)
                if(_explore(grid, r, c, rMax, cMax, visited))
                    count++;

        return count;
    }
};
