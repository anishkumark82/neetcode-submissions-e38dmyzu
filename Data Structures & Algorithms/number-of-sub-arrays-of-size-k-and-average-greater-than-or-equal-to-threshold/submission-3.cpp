class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // Fixed Window problem
        int R = min(k, static_cast<int>(arr.size()));
        // Assuming k >= arr.size().
        int sum = std::accumulate(arr.begin(), arr.begin()+R, 0);
        int avg = sum/k;
        int count = 0; 
        if(avg >= threshold)
            count++;
        int L = 0;
        while(R < arr.size())
        {
            sum -= arr[L++];
            sum += arr[R++];
            int avg = sum/k;
            if(avg >= threshold)
                count++;
        }
        return count;
    }
};