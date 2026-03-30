// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
    void quickSortHlper(vector<Pair>& pairs, int s, int e)
    {
        if (e <= s)
            return;
        int p = qSPartition(pairs, s, e);
        quickSortHlper(pairs, s, p-1);
        quickSortHlper(pairs, p+1, e);
    }
    int qSPartition(vector<Pair>&pairs, int s, int e)
    {
        int pivot = pairs[e].key;
        int slot = s;
        int cur = s;
        while(cur < e)
        {
            if(pairs[cur].key < pivot)
            {
                swap(pairs[cur], pairs[slot]);
                slot++;
            }
            cur++;
        }
        swap(pairs[e], pairs[slot]);
        return slot;
    }
public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSortHlper(pairs, 0, pairs.size()-1);
        return pairs;
    }
};
