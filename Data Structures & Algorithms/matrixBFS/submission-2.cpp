class Solution {
public:
    void _insertQ(vector<vector<int>> &grid,
                  queue<vector<int>> &Q, 
                  int r, int c, 
                  int rMax, int cMax, 
                  vector<vector<bool>> &visited)
    {
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;
        if(!rInBounds || !cInBounds)
            return;

        if(grid[r][c] == 1 || visited[r][c])
            return;
            
        visited[r][c] = true;
        Q.push({r,c});
    }

    int shortestPath(vector<vector<int>>& grid) {
        int rMax = grid.size();
        int cMax = grid[0].size();

        vector<vector<bool>> visited(rMax, vector<bool>(cMax, false));
        queue<vector<int>> Q;

        const vector<vector<int>> iLOC = {{-1, 0}, {1,0}, {0,-1}, {0,1}};

        // Adding the 0,0 into the queue.
        Q.push({0,0});
        visited[0][0] = true;
        int len = -1; 
        while(!Q.empty())
        {
            len++;
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                int r = Q.front()[0];
                int c = Q.front()[1];
                Q.pop();
                if(r == rMax-1 && c == cMax-1) // Reached the end point
                    return len;
                // Check if any of the adjacent unvisited positions can be inserted.
                for(auto i = 0; i < iLOC.size(); ++i)
                    _insertQ(grid, Q, r + iLOC[i][0], c + iLOC[i][1], rMax, cMax, visited);
            }
        }
        return -1;
    }
};
