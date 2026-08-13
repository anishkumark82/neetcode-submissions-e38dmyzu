class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        vector<int> chCount(26, 0);

        for(auto i = 0; i < s.length(); ++i)
        {
            chCount[s[i] - 'a']++;
            chCount[t[i] - 'a']--;
        }

        for(auto i = 0; i < 26; ++i)
            if(chCount[i] != 0)
                return false;
        return true;
    }
};
