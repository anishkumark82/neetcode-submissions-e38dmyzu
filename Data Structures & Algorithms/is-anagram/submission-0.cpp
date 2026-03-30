class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);
        if(s.length() != t.length())
            return false;

        for(auto i = 0; i < s.size(); ++i)
        {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(auto &f : freq)
            if(f != 0)
                return false;
        return true;
    }
};
