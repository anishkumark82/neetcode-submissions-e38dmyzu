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
        for (auto i = 0; i < pairs.size(); ++i)
        {           
            int j = i-1;
            while(j >= 0 && pairs[j+1].key < pairs[j].key)
            {
                swap(pairs[j+1], pairs[j]);
                j--;
            }
            out.push_back(pairs);
        }
        return out;
    }
};
