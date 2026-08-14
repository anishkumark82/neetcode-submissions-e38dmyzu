class Solution {
//    void insertNeighbors(vector<vector<int>>& image, queue<pair<int,int>> &Q, 
//                         int r, int c, int rMax, int cMax, int oC)
    void insertNeighbors(vector<vector<int>>& image, queue<pair<int,int>> &Q, 
                         int r, int c, int rMax, int cMax, int oC, 
                         vector<vector<bool>> &visited)

    {
        vector<vector<int>> nbrs = { {-1, 0 }, {0, -1}, {1, 0}, {0, 1} };

        for(auto &n : nbrs)
        {
            int rNew = r+n[0];
            int cNew = c+n[1];
            bool rInBounds = rNew >= 0 && rNew < rMax;
            bool cInBounds = cNew >= 0 && cNew < cMax;

            if(!rInBounds || !cInBounds)
                continue;

            if(visited[rNew][cNew])
                continue;

            if(image[rNew][cNew] != oC)
                continue;

            Q.push({rNew, cNew});
            visited[rNew][cNew] = true;
        }    
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> Q;
        int oC = image[sr][sc];
        int rMax = image.size();
        int cMax = image[0].size();
        vector<vector<bool>> visited(rMax, vector<bool>(cMax, false));

        Q.push({sr, sc});
        visited[sr][sc] = true;

        while(!Q.empty())
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                auto [r,c] = Q.front();
                Q.pop();
                image[r][c] = color;
                insertNeighbors(image, Q, r, c, rMax, cMax, oC, visited);
            }
        }
        return image;
    }
};