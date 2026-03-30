class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;

        while(l < r)
        {
            int sum = numbers[l] + numbers[r];
            if(sum == target)
                return {l+1, r+1};
            else if(sum > target) // Need to move the right pointer
                r--;
            else // sum too small so move the l pointer
                l++;
        }
        return {0,0};
    }
};
