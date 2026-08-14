class Solution {
private:
    void insertQ(vector<vector<int>> &grid, queue<pair<int,int>> &Q, int r, int c, int rMax, int cMax, 
                 vector<vector<bool>> &visited)
    {
        vector<vector<int>> nbrs{{-1, 0}, {1,0}, {0, -1}, {0, 1}};
        for(auto &n : nbrs)
        {
            int newR = r + n[0];
            int newC = c + n[1];
            bool rInBounds = newR >= 0 && newR < rMax;
            bool cInBounds = newC >= 0 && newC < cMax;

            if (!rInBounds || !cInBounds)
                continue;
            
            if(grid[newR][newC] != 0 || visited[newR][newC])
                continue;
            
            visited[newR][newC] = true;
            Q.push({newR, newC});
        }
    }
public:
    int shortestPath(vector<vector<int>>& grid) {
        int rMax = grid.size();
        int cMax = grid[0].size();

        if(grid[0][0] != 0 || grid[rMax-1][cMax-1] != 0)
            return -1;

        // BFS 
        queue<pair<int,int>> Q;
        vector<vector<bool>> visited(rMax, vector<bool>(cMax, false));
        int length = 0;

        Q.push({0,0});
        visited[0][0] = true;

        while(!Q.empty())
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                auto [r, c] = Q.front();
                Q.pop();

                if(r == rMax-1 && c == cMax-1)
                    return length;
                
                insertQ(grid, Q, r, c, rMax, cMax, visited);
            }
            length++;
        }
        return -1;
    }
};
