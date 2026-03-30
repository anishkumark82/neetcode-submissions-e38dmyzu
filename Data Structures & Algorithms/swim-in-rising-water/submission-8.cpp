using GRID_TUPLE = tuple<int, int, int>; 
class Solution {

public:
    int swimInWater(vector<vector<int>>& grid) {
        // Dijkstra's algorithm
        int rMax = grid.size();
        int cMax = grid[0].size();

        priority_queue<GRID_TUPLE, vector<GRID_TUPLE>, greater<GRID_TUPLE>> minHeap;
        vector<vector<bool>> visited(rMax, vector<bool>(cMax, false));

        minHeap.push(make_tuple(grid[0][0], 0, 0));

        while(!minHeap.empty())
        {
            auto [w, r, c] = minHeap.top();
            minHeap.pop();

            if(visited[r][c])
                continue;
            
            if(r == rMax-1 && c == cMax-1)
                return w;

            visited[r][c] = true;
            
            // Insert its neighbors
            for(int i = 0; i < NBR.size(); ++i)
            {
                int newR = r+NBR[i][0];
                int newC = c+NBR[i][1];
                bool rInBounds = newR >= 0 && newR < rMax;
                bool cInBounds = newC >= 0 && newC < cMax;
                
                if(!rInBounds || !cInBounds)
                    continue;
                
                if(!visited[newR][newC])
                {
                    auto val = max(grid[newR][newC], w);
                    minHeap.push(make_tuple(val, newR, newC));
                }
            }
        }
        return -1;
    }
    vector<vector<int>> NBR = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
