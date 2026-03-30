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
            return {};
        out.push_back(pairs);

        for(auto i = 1; i < pairs.size(); ++i)
        {
            for(int j = i-1; j >= 0 && (pairs[j+1].key < pairs[j].key); --j)
                swap(pairs[j], pairs[j+1]);
            out.push_back(pairs);
        }
        return out;
    }
};
