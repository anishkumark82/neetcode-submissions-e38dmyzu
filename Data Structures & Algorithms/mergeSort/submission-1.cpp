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
    void mergeSort(vector<Pair>& pairs, int start, int end){
        if(start >= end)
            return;
        int mid = start + (end-start)/2;
        mergeSort(pairs, start, mid);
        mergeSort(pairs, mid+1, end);
        merge(pairs, start, mid, end);
    }
    
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        mergeSort(pairs, 0, pairs.size()-1);
        return pairs;
    }
    private:
        void merge(vector<Pair>& pairs, int start, int mid, int end)
        {
            vector<Pair> L(pairs.begin()+start, pairs.begin()+mid+1);
            vector<Pair> R(pairs.begin()+mid+1, pairs.begin()+end+1);
            
            int i = 0; // Index of L
            int j = 0; // Index of R
            int k = start; // Index of pairs
            while(i < L.size() && j < R.size())
            {
                if(L[i].key <= R[j].key)
                    pairs[k++] = L[i++];
                else
                    pairs[k++] = R[j++];
            }
            while(i < L.size())
                pairs[k++] = L[i++];

            while(j < R.size())
                pairs[k++] = R[j++];
        }
};
