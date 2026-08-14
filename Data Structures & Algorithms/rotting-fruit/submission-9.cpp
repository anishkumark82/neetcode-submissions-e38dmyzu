class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS 
        int total = 0;
        int rMax = grid.size();
        int cMax = grid[0].size();
        queue<pair<int,int>> Q;
        for(auto r = 0; r < rMax; ++r)
            for(auto c = 0; c < cMax; ++c)
            {
                if(grid[r][c] == 1)
                    total++;
                else if(grid[r][c] == 2)
                    Q.push({r,c});
            }
        total += Q.size();

        int length = 0;
        while(!Q.empty())
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                auto [r, c] = Q.front();
                Q.pop();
                total--;
                vector<vector<int>> nbr{{-1,0}, {1,0}, {0, -1}, {0, 1}};
                if(total == 0)
                    return length;
                for(auto &n : nbr)
                {
                    int newR = r + n[0];
                    int newC = c + n[1];
                    bool rInBounds = newR >= 0 && newR < rMax;
                    bool cInBounds = newC >= 0 && newC < cMax;

                    if(!rInBounds || !cInBounds)
                        continue;
                    
                    if(grid[newR][newC] != 1)
                        continue;
                    
                    Q.push({newR, newC});
                    grid[newR][newC] = 2;
                }
            }
            length++;
        }
        return total ? -1 : 0;
    }
};
