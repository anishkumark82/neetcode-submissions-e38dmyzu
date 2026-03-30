class Solution {
public:
    int climbStairs(int n) {
        vector<int> numSteps(n+1, 0);
        if(n <= 1)
            return 1;
        numSteps[0] = 1;
        numSteps[1] = 1;

        for(auto i = 2; i <= n; ++i)
            numSteps[i] = numSteps[i-1] + numSteps[i-2];
        return numSteps[n];     
    }
};
