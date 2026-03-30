using PAIRINT = pair<int,int>;
class Solution {
private:
    void _insertHeap(vector<vector<int>>& grid, int r, int c, int pVal) 
    {
        
        bool rInBounds = r >= 0 && r < grid.size();
        bool cInBounds = c >= 0 && c < grid[0].size();

        if(!rInBounds || !cInBounds)
            return;
        
        minHeap.push({max(pVal, grid[r][c]), r , c});

    }                    
public:
    int swimInWater(vector<vector<int>>& grid) {
        shortestPath.resize(grid.size(), vector<int>(grid[0].size(), -1));
        minHeap = priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>();

        minHeap.push({grid[0][0], 0, 0});
        while(!minHeap.empty())
        {
            vector<int> p = minHeap.top();
            minHeap.pop();
            int r = p[1];
            int c = p[2];

            if(shortestPath[r][c] != -1) // already visited
                continue;
            
            shortestPath[r][c] = p[0];
            _insertHeap(grid, r-1, c, p[0]);
            _insertHeap(grid, r+1, c, p[0]);
            _insertHeap(grid, r, c-1, p[0]);
            _insertHeap(grid, r, c+1, p[0]);
        }

        return shortestPath.back().back();
    }
private:
    vector<vector<int>> shortestPath;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

};
