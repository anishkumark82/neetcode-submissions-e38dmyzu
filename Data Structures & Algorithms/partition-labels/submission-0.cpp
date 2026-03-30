class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> charCnt;
        unordered_set<char> curSet;

        for(auto &ch : s)
            charCnt[ch]++;
        
        int L = 0;
        int R = 0;
        vector<int> out;
        while(R < s.length())
        {
            curSet.insert(s[R]);
            charCnt[s[R]]--;
            if(charCnt[s[R]] == 0)
            {
                curSet.erase(s[R]);
                if(curSet.size() == 0)
                {
                    out.push_back(R-L+1);
                    L = R+1;
                }
            }
            R++;
        }
        return out;
    }
};
