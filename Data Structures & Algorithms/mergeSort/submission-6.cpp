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
    void mergeSortHlper(vector<Pair>& pairs, int low, int high)
    {
        if(low >= high)
            return;
        
        int m = low + (high - low)/2;   
        mergeSortHlper(pairs, low, m); 
        mergeSortHlper(pairs, m+1, high); 

        merge(pairs, low, m, high); 
    }

    void merge(vector<Pair>& pairs, int low, int m, int high) 
    {
        vector<Pair> L(pairs.begin()+low, pairs.begin()+m+1); 
        vector<Pair> R(pairs.begin()+m+1, pairs.begin()+high+1); 

        int k = low; 
        int l = 0;
        int r = 0;
        while(l < L.size() && r < R.size())
        {
            if(L[l].key <= R[r].key)
                pairs[k++] = L[l++]; 
            else
                pairs[k++] = R[r++];
        }
        while(l < L.size())
            pairs[k++] = L[l++];
        while(r < R.size())
            pairs[k++] = R[r++];
    }

    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if (pairs.empty()) return pairs;
        mergeSortHlper(pairs, 0, pairs.size()-1);
        return pairs;
    }
};
