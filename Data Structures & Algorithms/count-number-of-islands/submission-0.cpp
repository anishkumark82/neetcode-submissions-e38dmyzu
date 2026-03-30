class Solution {
private:
    bool _explore(vector<vector<char>> &grid, int r, int c, vector<vector<bool>> &visited)
    {
        bool rInBounds = r >= 0 && r < grid.size();
        bool cInBounds = c >= 0 && c < grid[0].size();

        if(!rInBounds || !cInBounds || visited[r][c])
            return false;
        
        if(grid[r][c] == '0')
            return false;

        visited[r][c] = true;
        bool foundIsland = true;
        foundIsland |= _explore(grid, r+1, c, visited);
        foundIsland |= _explore(grid, r-1, c, visited);
        foundIsland |= _explore(grid, r, c-1, visited);
        foundIsland |= _explore(grid, r, c+1, visited);
        return foundIsland;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int count = 0;
        for(auto r = 0; r < grid.size(); ++r)
            for(auto c = 0; c < grid[0].size(); ++c)
                count += (_explore(grid, r, c, visited) == true);
        return count;
    }
};
