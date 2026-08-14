class Solution {
private:
    void insertQ(vector<vector<int>> &grid, queue<pair<int, int>> &Q, int r, int c, int n, vector<vector<bool>> &visited)
    {
        vector<vector<int>> nbrs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1,1}};

        for(auto &nb : nbrs)
        {
            int newR = r + nb[0];
            int newC = c + nb[1];
            bool rInBounds = newR >= 0 && newR < n;
            bool cInBounds = newC >= 0 && newC < n;
            if(!rInBounds || !cInBounds)
                continue;
            
            if(grid[newR][newC] != 0 || visited[newR][newC])
                continue;
            
            visited[newR][newC] = true;
            Q.push({newR, newC});
        }
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> Q;
        int length = 1;
        
        Q.push({0,0});
        visited[0][0] = true;

        while(!Q.empty())
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                auto [r, c] = Q.front();
                Q.pop();

                if(r == n-1 && c == n-1)
                    return length;
                
                insertQ(grid, Q, r, c, n, visited);
            }
            length++;
        }
        return -1; 
    }
};