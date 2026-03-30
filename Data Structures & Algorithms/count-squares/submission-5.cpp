class hashFunc{
public:
    size_t operator()(const pair<int,int> &p) const
    {
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1^h2;
    }
};
class CountSquares {
public:
    CountSquares() {
        
    }
    
    void add(vector<int> p) {
        pMap[{p[0], p[1]}]++; 
    }
    
    int count(vector<int> p) {
        // Always look for the diagonal element
        // Assume (px,py) -- current pointer
        // Candidate Diagonal = (x,y)
        // if there exist (px,y) & (x,py) then we can form a square
        // cnt(x,y) * cnt(px,y) * cnt(x, py) 
        int px = p[0];
        int py = p[1];
        int total = 0;
        for(auto &itr : pMap)
        {
            auto [x,y] = itr.first;
            if(x == px && y == py)
                continue;
            if(abs(x-px) == abs(y-py) && 
               pMap.find({x,py}) != pMap.end() && pMap.find({px,y}) != pMap.end() )
                total += itr.second * pMap[{x,py}] * pMap[{px,y}];
        }
        return total;
    }
private:
    unordered_map<pair<int,int>, int, hashFunc> pMap;
};
