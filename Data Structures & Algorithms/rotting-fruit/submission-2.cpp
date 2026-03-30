class Solution {
public:
    void _insertQ(vector<vector<int>> &grid, int r, int c)
    {
        bool rInBounds = r >= 0 && r < grid.size();
        bool cInBounds = c >= 0 && c < grid[0].size();

        if(!rInBounds || !cInBounds || grid[r][c] != 1)
            return;
        
        grid[r][c] = 2;
        Q.push({r,c});
        good--;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // find all the rotten oranges
        for(auto r = 0; r < grid.size(); ++r)
            for(auto c = 0; c < grid[0].size(); ++c)
                if(grid[r][c] == 2)
                    Q.push({r,c});
                else if(grid[r][c] == 1)
                    good++;

        while(good > 0 && !Q.empty() )
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                int r = Q.front().first;
                int c = Q.front().second;
                Q.pop();
                
                _insertQ(grid, r-1, c);
                _insertQ(grid, r+1, c);
                _insertQ(grid, r, c-1);
                _insertQ(grid, r, c+1);
            }
            steps++;
        }
        return (good == 0) ? steps : -1;
    }
private:
    queue<pair<int,int>> Q;
    int good = 0;
    int steps = 0;
};
