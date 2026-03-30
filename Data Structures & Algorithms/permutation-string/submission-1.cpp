class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int L = 0;
        unordered_map<char, int>chMap;
        for(auto &s : s1)
            chMap[s]++;
        
        while(L < s2.size())
        {
            if(chMap.find(s2[L]) != chMap.end())
                break;
            ++L;
        }
        int numMatch = 0;
        // Handling courner cases
        if(L == s2.size() || s2.size()-L < s1.size())
            return false;

        int R = L;
        while(R < s2.size())
        {
            if(chMap.find(s2[R]) != chMap.end() && chMap[s2[R]] != 0)
            {
                chMap[s2[R]]--;
                numMatch++;
                ++R;
                if(numMatch == s1.size())
                    return true;
            }
            else
            {
                chMap[s2[L]]++;
                numMatch--;
                ++L;
            }
        }
        return false;
    }
};
