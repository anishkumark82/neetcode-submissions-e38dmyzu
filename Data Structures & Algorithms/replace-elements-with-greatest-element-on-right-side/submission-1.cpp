class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> out(arr.size());
        int maxVal = -1;
        for(int i = arr.size()-1; i >= 0; --i)
        {
            out[i] = maxVal;
            maxVal = max(maxVal, arr[i]); 
        }
        return out;
    }
};