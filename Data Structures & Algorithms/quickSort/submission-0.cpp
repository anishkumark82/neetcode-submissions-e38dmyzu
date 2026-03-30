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
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSortHelper(pairs, 0, pairs.size()-1);
        return pairs;
    }
private:
    void quickSortHelper(vector<Pair>& pairs, int s, int e)
    {
        if(s >= e)
            return;
        int pivot = partition(pairs, s, e);
        quickSortHelper(pairs, s, pivot-1);
        quickSortHelper(pairs, pivot+1, e);
    }

    int partition(vector<Pair>& pairs, int s, int e)
    {
        int pivot = pairs[e].key;
        int pos = s;
        for(auto i = s; i < e; ++i)
        {
            if(pairs[i].key < pivot)
            {
                swap(pairs[i], pairs[pos]);
                pos++;
            }
        }
        swap(pairs[pos], pairs[e]);
        return pos;
    }
};
