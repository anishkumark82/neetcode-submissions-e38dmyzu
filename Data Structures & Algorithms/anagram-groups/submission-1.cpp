class Solution {
public:

    string findFreqStr(string &str)
    {
        // O(m)
        stringstream fStr;
        vector<char>chCount(26, 0);
        for(auto &ch : str)
            chCount[ch-'a']++;
        
        for(char i = 0; i < 26; ++i)
            fStr << (i+'a') << chCount[i];
        return fStr.str();
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // frequency string of each string
        // then use the frequency string as a key for a map and vector of original strings as values
        // then iterate through the map and store into a vector

        // O(m * n) - Time
        // O(m * n) - Space
        unordered_map<string, vector<string>> fMap;
        for(auto &str : strs) // O(m*n)
        {
            string fStr = findFreqStr(str);
            fMap[fStr].push_back(str);
        }
        vector<vector<string>> out;
        for(auto &itr : fMap) //O(n)
            out.push_back(itr.second);
        return out;
    }
};
