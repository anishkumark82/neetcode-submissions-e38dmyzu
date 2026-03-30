const int TREASURE = 0;
const int INF = 2147483647;
const int WATER = -1;
class Solution {
private:
    vector<vector<int>> NBRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    void insertQNbrs(queue<pair<int,int>> &Q, vector<vector<int>> &grid, 
                     int r, int c, int rMax, int cMax)
    {
        for(auto &N : NBRS)
        {
            int newR = r + N[0];
            int newC = c + N[1];
            bool rInBounds = newR >= 0 && newR < rMax;
            bool cInBounds = newC >= 0 && newC < cMax;
            if(!rInBounds || !cInBounds)
                continue;
            
            if(grid[newR][newC] != INF)
                continue;
            grid[newR][newC]= grid[r][c] + 1;
            Q.push({newR, newC});
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> Q;
        int rMax = grid.size();
        int cMax = grid[0].size();
        // identify and store all the treasure co-ordinates -- O(r,c)
        for(auto r = 0; r < grid.size(); ++r)
            for(auto c = 0; c < grid[0].size(); ++c)
                if(grid[r][c] == TREASURE)
                    Q.push({r,c});
        while(!Q.empty())
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                auto [r, c] = Q.front();
                Q.pop();
                insertQNbrs(Q, grid, r, c, rMax, cMax);
            }
        }
    }
};
