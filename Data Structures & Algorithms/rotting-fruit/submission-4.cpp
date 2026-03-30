class Solution {
private:
    void _insertQ(vector<vector<int>> &grid, queue<vector<int>> &Q, 
                  int r, int c, int rMax, int cMax)
    {
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;
        if(!rInBounds || !cInBounds)
            return;
        
        if(grid[r][c] != 1)
            return;
        
        grid[r][c] = 2;
        Q.push({r,c});
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // find all rotten and good fruits
        int rMax = grid.size();
        int cMax = grid[0].size();
        int fresh = 0;
        int rotten = 0;
        queue<vector<int>> Q;
        const vector<vector<int>> N = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = -1;

        int total = 0;
        int cnt = 0;
        
        for(auto r = 0; r < rMax; ++r)
            for(auto c = 0; c < cMax; ++c)
            {
                if(grid[r][c] == 1)
                    total++;
                else if(grid[r][c] == 2)
                {
                    total++;
                    Q.push({r,c});
                }
            }

        if(total == 0)
            return 0;
        
        while(!Q.empty())
        {
            ++time;
            int qSize = Q.size();
            cnt += qSize;
            for(auto i = 0; i < qSize; ++i)
            {
                int r = Q.front()[0];
                int c = Q.front()[1];
                Q.pop();

                for(auto j = 0; j < N.size(); ++j)
                    _insertQ(grid, Q, r+N[j][0], c+N[j][1], rMax, cMax);
            }
        }
        
        return cnt != total ? -1 : time;
    }
};
