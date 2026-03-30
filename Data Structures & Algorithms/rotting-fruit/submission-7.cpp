class Solution {
private:
    vector<vector<int>> dg = {{-1, 0}, {1,0}, {0,-1}, {0,1}};
    void insertQ(queue<pair<int,int>> &Q, vector<vector<int>>& grid, int r, int c)
    {
        int rMax = grid.size();
        int cMax = grid[0].size();
        bool rInBounds =  r >= 0 && r < rMax;
        bool cInBounds =  c >= 0 && c < cMax;

        if(!rInBounds || !cInBounds)
            return;

        if(grid[r][c] != 1)
            return;

        grid[r][c] = 2;
        Q.push({r,c});
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Find all the number of oranges and number of rotten oranges
        // Push the rotten oranges into the queue at the first level
        // Already rotten i can just change to 2 also or i can keep track of visited nodes

        int numOrg = 0;
        int numRotten = 0;
        queue<pair<int,int>> Q;
        int time = -1;
        int numP = 0;

        for(auto r = 0; r < grid.size(); ++r)
            for(auto c = 0; c < grid[0].size(); ++c)
            {
                numOrg += (grid[r][c] != 0) ? 1 : 0;
                if(grid[r][c] == 2)
                {
                    numRotten++;
                    Q.push({r,c});
                }
            }
        if(numOrg == 0)
            return 0;
                
        while(!Q.empty())
        {
            time++;
            int qSize = Q.size();
            numP += qSize;
            for(auto i = 0; i < qSize; ++i)
            {
                auto [r,c] = Q.front();
                Q.pop();
                insertQ(Q, grid, r+1, c);
                insertQ(Q, grid, r-1, c);
                insertQ(Q, grid, r, c+1);
                insertQ(Q, grid, r, c-1);
            }
        }
        return (numP != numOrg) ? -1 : time;
    }
};
