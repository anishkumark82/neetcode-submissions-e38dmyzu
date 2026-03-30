class Solution {
private:
    void _insertQ(vector<vector<int>> &grid, queue<vector<int>> &Q, 
                  int r, int c, int rMax, int cMax, 
                  vector<vector<bool>> &visited)
    {
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;
        if(!rInBounds || !cInBounds)
            return;

        if(grid[r][c] != 0 || visited[r][c])
            return;
        
        visited[r][c] = true;
        Q.push({r,c});
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rMax = grid.size();
        int cMax = grid[0].size();

        // Boundary condition check
        if(grid[0][0] != 0 || grid[rMax-1][cMax-1] != 0)
            return -1;

        const vector<vector<int>>iLOC = {{-1, -1}, {-1,0}, {-1,1}, 
                                         {0,-1}, {0,1}, 
                                         {1,-1}, {1,0}, {1,1} };
        queue<vector<int>> Q;
        vector<vector<bool>>visited(rMax, vector<bool>(cMax, false));

        // Push the starting point
        Q.push({0,0});
        visited[0][0] = true;
        int sLen = 0;
        while(!Q.empty())
        {
            sLen++;
            int qSize = Q.size();

            for(auto i = 0; i < qSize; ++i)
            {
                int r = Q.front()[0];
                int c = Q.front()[1];
                Q.pop();

                if((r == rMax-1) && (c == cMax-1))
                    return sLen;
                
                // Push to the queue
                for(auto j = 0; j < iLOC.size(); ++j)
                    _insertQ(grid, Q, r+iLOC[j][0], c+iLOC[j][1], rMax, cMax, visited);
            }
        }
        return -1;
    }
};