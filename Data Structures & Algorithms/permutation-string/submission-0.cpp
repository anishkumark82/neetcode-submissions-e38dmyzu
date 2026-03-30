class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s2.size() < s1.size())
            return false;

        vector<int> s1CharMap(26,0);
        vector<int> s2CharMap(26,0);

        for(auto &ch : s1)
            s1CharMap[ch-'a']++;


        int l = 0;
        for(auto r = 0; r < s2.size(); ++r)
        {
            s2CharMap[s2[r]-'a']++;

            if(r < s1.size()-1)
                continue;
            if(s1CharMap == s2CharMap)
                return true;
            
            s2CharMap[s2[l]-'a']--;
            l++;
        }
        return false;
    }
};
