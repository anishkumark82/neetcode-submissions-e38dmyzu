class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int prevSign = 0; // NA- 0  - equal, 1 - >, 2 <  
        int maxLen = 1;
        int curLen = 1;

        for(int i = 1; i < arr.size(); ++i)
        {
            int curSign = 0;
            // Determine Sign
            if(arr[i-1] < arr[i])
                curSign = 2;
            else if(arr[i-1] > arr[i])
                curSign = 1;

            // Check for Sign flip
            if(curSign != 0 && (prevSign == -1 || prevSign != curSign))
                curLen++;
            else //In all other cases
                curLen = (curSign == 0) ? 1 : 2;
            prevSign = curSign;

            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};