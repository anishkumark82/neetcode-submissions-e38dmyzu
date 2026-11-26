
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>minHeap;
        minHeap.push({grid[0][0], 0, 0});
        const vector<vector<int>> MOVES{{0,-1}, {0,1}, {-1,0},{1,0}};
        while(!minHeap.empty() && visited.back().back() != true)
        {
            auto [wt, r, c] = minHeap.top();
            minHeap.pop();
            if(visited[r][c])
                continue;
            
            visited[r][c] = true;
            if(r == n-1 && c == n-1)
                return wt;
            // for directions insert
            for(auto &M : MOVES)
            {
                int newR = r + M[0];
                int newC = c + M[1];
                bool rInBounds = newR >= 0 && newR < n;
                bool cInBounds = newC >= 0 && newC < n;
                if(!rInBounds || !cInBounds)
                    continue;
                if(visited[newR][newC])
                    continue;

                minHeap.push({max(wt, grid[newR][newC]), newR, newC});
            } 
        }
        throw;
    }
};
