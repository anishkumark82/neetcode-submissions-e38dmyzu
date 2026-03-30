class hashFunc{
public:
    size_t operator()(const vector<int> &p) const{
        auto h1 = hash<int>{}(p[0]);
        auto h2 = hash<int>{}(p[1]);
        return h1^h2;
    }
};
class Solution {

private:
    void _dfs(int r, int c, 
              int prev, int rMax, int cMax, vector<vector<int>> &hts, 
              unordered_set<vector<int>, hashFunc> &selected)
    {
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;

        if(!rInBounds || !cInBounds)
            return;
       
        if(hts[r][c] < prev) // reverse the condition from the edges
            return;

        if(selected.count({r,c})) // Already explored all its neighbors ??
            return;

        selected.insert({r,c});  
        vector<vector<int>> NBRS = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto &n : NBRS)
            _dfs(r+n[0], c+n[1], hts[r][c], rMax, cMax, hts, selected);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        unordered_set<vector<int>, hashFunc> selectedP;
        unordered_set<vector<int>, hashFunc> selectedA;
        int rMax = heights.size();
        int cMax = heights[0].size();
        // We can reverse the logic
        // Water can flow from ocean inwards if >= number
        for(auto c = 0; c < cMax; ++c)
        {
            _dfs(0, c, -1, rMax, cMax, heights, selectedP);
            _dfs(rMax-1, c, -1, rMax, cMax, heights, selectedA);
        }

        for(auto r = 0; r < rMax; ++r)
        {
            _dfs(r, 0, -1, rMax, cMax, heights, selectedP);
            _dfs(r, cMax-1, -1, rMax, cMax, heights, selectedA);
        }

        vector<vector<int>> out;
        for(auto &itr : selectedP)
        {
            if(selectedA.count(itr))
                out.push_back(itr);
        }
        return out;
    }
};
