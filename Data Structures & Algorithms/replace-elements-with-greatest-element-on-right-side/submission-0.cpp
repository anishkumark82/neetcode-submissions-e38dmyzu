class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxEle = -1;
        
        for(int i = arr.size()-1; i >= 0; --i)
        {
            int curEle = arr[i];
            arr[i] = maxEle;
            maxEle = max(maxEle, curEle);
        }
        return arr;
    }
};