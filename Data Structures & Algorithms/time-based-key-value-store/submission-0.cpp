class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dS[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // Binary search to find the nearest possible match
        string ret = "";
        if(!dS.count(key))
            return ret;
        vector<pair<int, string>> &cur = dS[key];        
        
        int l = 0;
        int h = cur.size()-1;
        
        while(l <= h)
        {
            int m = (l + h)/2;
            if(cur[m].first < timestamp)
            {
                ret = cur[m].second;
                l = m+1;
            }
            else if(timestamp < cur[m].first)
                h = m-1;
            else // found the exact match
                return cur[m].second;
        }
        return ret;
    }
    unordered_map<string, vector<pair<int, string>>> dS;
};
