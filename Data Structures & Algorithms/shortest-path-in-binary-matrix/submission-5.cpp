class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // BFS algorithm on the matrix
        // 8 degrees of freedom
        //        - (r-1,c-1)  - (r-1, c)    - (r-1, c+1)
        //        - (r,c-1)    x             - (r, c+1)
        //        - (r+1,c-1)  - (r+1, c)    - (r+1, c+1)

        // grid=[[0,1,0],
        //       [1,0,0],
        //       [1,1,0]]
        queue<pair<int,int>> Q;
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        vector<vector<bool>>visited(n, vector<bool>(n, false));
        Q.push({0,0});
        visited[0][0] = true;
        int length = 0;

        while(!Q.empty())
        {
            int qSize = Q.size();
            length++;
            for(auto i = 0; i < qSize; ++i)
            {
                auto [r,c] = Q.front();
                Q.pop();
                if(r == n-1 && c == n-1)
                    return length;
                
                vector<vector<int>> nbrs = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1,-1}, {1, 0}, {1,1}};
                for (auto &nb : nbrs)
                {
                    int rNew = r + nb[0];
                    int cNew = c + nb[1];

                    bool rInBounds = rNew >= 0 && rNew < n;
                    bool cInBounds = cNew >= 0 && cNew < n;
                    if(!rInBounds || !cInBounds)
                        continue;

                    if(grid[rNew][cNew] != 0 || visited[rNew][cNew])
                        continue;

                    Q.push({rNew, cNew});
                    visited[rNew][cNew] = true;
                }
            }
        }
        return -1;
    }
};