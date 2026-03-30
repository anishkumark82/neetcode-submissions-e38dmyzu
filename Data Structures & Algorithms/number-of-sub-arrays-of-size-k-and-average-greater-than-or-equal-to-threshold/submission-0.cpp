class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(arr.size() < k)
            return 0;

        int l = 0;
        int r = 0;
        int sum = 0;

        for(r = 0; r < k; ++r)
            sum += arr[r];
        
        int count = 0;
        if(sum/k >= threshold)
            count++;
        
        for(r = k; r < arr.size(); ++r)
        {
            sum -= arr[r-k];
            sum += arr[r];

            if(sum/k >= threshold)
                count++;
        }
        return count;
    }
};