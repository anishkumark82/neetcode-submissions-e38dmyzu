class Solution {
private:
    string findFreqStr(string &s)
    {
        string fStr = "";
        vector<int> chMap(26, 0);
        for(auto &ch : s)
            chMap[ch-'a']++;

        for(auto i = 0; i < 26; ++i)
        {
            if(chMap[i] != 0)
            {
                stringstream ss;
                ss << static_cast<char>(i) + 'a'<< chMap[i];
                fStr += ss.str();
            }
        }
        return fStr;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> aMap;
        
        // Frequency string for each string
        for(auto &s : strs)
        {
            string fStr = findFreqStr(s);
            aMap[fStr].push_back(s);
        }
        vector<vector<string>> out;    
        for(auto itr : aMap)
            out.push_back(itr.second);
        return out;
    }
};
