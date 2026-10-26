// 2, 4, 3, 2, 2, 5, 1, 4
// 
//             LR       
// nextUp - false
// maxLen = 3

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() <= 1)
            return arr.size();

        int maxLen = 1;
        bool nextUp = false;
        int L = 0;
        int R = 1;

        while(R < arr.size())
        {
            if(L+1 == R)
                if(arr[L] < arr[R])
                    nextUp = false;
                else if(arr[L] > arr[R])
                    nextUp = true;
                else
                    L = R;
            else
            {
                if(!nextUp && arr[R-1] > arr[R])
                    nextUp = true;
                else if(nextUp && arr[R-1] < arr[R])
                    nextUp = false;
                else
                {
                    R--;
                    L = R;
                }
            } 
            maxLen = max(maxLen, R-L + 1);
            R++;
        }
        return maxLen;
    }
};