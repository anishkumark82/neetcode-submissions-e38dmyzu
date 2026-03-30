// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> out;
        if(pairs.size() == 0)
            return out;
        out.push_back(pairs); 
        for(auto i = 1; i < pairs.size(); ++i)
        {
            int j = i-1;
            while(j >= 0 && pairs[j].key > pairs[j+1].key)
            {
                swap(pairs[j], pairs[j+1]);
                j--;
            }
            out.push_back(pairs);
        }
        return out;
    }
};
