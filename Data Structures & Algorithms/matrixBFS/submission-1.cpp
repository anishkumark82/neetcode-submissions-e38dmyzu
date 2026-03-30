class Solution {
private:
    void _insertQ(vector<vector<int>> &grid, int r, int c)
    {
        bool rInBounds = r >= 0 && r < grid.size();
        bool cInBounds = c >= 0 && c < grid[0].size();

        if(!rInBounds || !cInBounds || visited[r][c])
            return;
        
        if(grid[r][c] == 1)
            return;
        
        visited[r][c] = true;
        Q.push({r,c});
    }
public:
    int shortestPath(vector<vector<int>>& grid) {

        if(grid[0][0] == 1)
            return -1;
        visited.resize(grid.size(), vector<bool>(grid[0].size(), false));
        _insertQ(grid, 0, 0);
        int level = -1;
        while(!Q.empty())
        {
            level++;
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                pair<int,int> ele = Q.front();
                Q.pop();
                int r = ele.first;
                int c = ele.second;

                if(r == grid.size()-1 && c == grid[0].size()-1)
                    return level;

                _insertQ(grid,r+1, c);
                _insertQ(grid,r-1, c);
                _insertQ(grid,r, c+1);
                _insertQ(grid,r, c-1);
            }
        }
        return -1;
    }
private:
        queue<pair<int,int>> Q;
        vector<vector<bool>>visited;

};
