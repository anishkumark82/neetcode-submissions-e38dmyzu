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
    void mergeSortHelper(vector<Pair>& pairs, int start, int end)
    {
        if(end <= start)
            return;
        
        int mid = (start+end)/2;
        mergeSortHelper(pairs, start, mid);
        mergeSortHelper(pairs, mid+1, end);
        merge(pairs, start, mid, end);
    }
    void merge(vector<Pair>& p, int start, int mid, int end)
    {
        vector<Pair>left(p.begin()+start, p.begin()+mid+1);
        vector<Pair>right(p.begin()+mid+1, p.begin()+end+1);
        int k = start;
        int l = 0;
        int r = 0;
        while(l < left.size() && r < right.size())
        {
            if(left[l].key <= right[r].key)
                p[k++] = left[l++];
            else
                p[k++] = right[r++];
        }
        while(l < left.size())
            p[k++] = left[l++];

        while(r < right.size())
            p[k++] = right[r++];
    }
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        mergeSortHelper(pairs, 0, pairs.size()-1);
        return pairs;
    }
};
