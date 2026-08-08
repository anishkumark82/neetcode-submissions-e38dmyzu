// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
private: 
    int _partition(vector<Pair>& p, int low, int high)
    {
        int pivot = p[high].key;

        // When paritioning bring all elements less than pivot to the left and 
        // all elements greater than pivot to the right
        int left = low;
        for(auto i = low; i < high; ++i)
        {
            if(p[i].key < pivot)
            {
                swap(p[i], p[left]);
                left++;
            }
        }

        swap(p[left], p[high]);
        return left;
    }

    void quickSortHelper(vector<Pair>& pairs, int low, int high)
    {
        if(low >= high)
            return;
        
        int p = _partition(pairs, low, high);
        quickSortHelper(pairs, low, p-1);
        quickSortHelper(pairs, p+1, high);
    }
public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSortHelper(pairs, 0, pairs.size()-1);
        return pairs;
    }
};
