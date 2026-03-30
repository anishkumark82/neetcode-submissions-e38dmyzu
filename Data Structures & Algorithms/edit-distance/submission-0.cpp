class Solution {
    int _dfs(int i1, int i2, string &w1, string &w2)
    {
        if(i1 == w1.size() && i2 == w2.size())
            return 0;
        
        if(i1 == w1.size())
            return w2.size()-i2; // insert that many characters
        if(i2 == w2.size())
            return w1.size()-i1; // delete that many characters
        
        int minDist = 0;
        if(w1[i1] == w2[i2])
            minDist = _dfs(i1+1, i2+1, w1, w2); // no operations needed
        else
        {
            // 3 options
            //1. Insert the same character as w2[i2] 
            minDist = 1 + _dfs(i1, i2+1, w1, w2);
            //2. Delete a character at i2
            minDist = min(minDist, 1 + _dfs(i1+1, i2, w1, w2));
            //3. Replace a character
            minDist = min(minDist, 1 + _dfs(i1+1, i2+1, w1, w2));
        }
        return minDist;
    }
public:
    int minDistance(string word1, string word2) {
        return _dfs(0, 0, word1, word2);
    }
};
