class Solution {
public:
    bool isHappy(int n) {
        // maximum square Sum = 9^2 + 9^2 + 9^2 = 81 + 81 + 81 =  243 
        vector<int> freq(250, 0);
        while(n != 1)
        {
            int tmp = n; // 100
            int sumSqr = 0; // 0
            while(tmp) // 100, 10, 1
            {
                int d = tmp % 10; //0 0 1
                tmp = tmp / 10; // 100/10 = 10 1 0
                sumSqr += (d*d); // 0 0 1
            }
            if(freq[sumSqr] != 0)
                return false;
                
            freq[sumSqr]++;
            n = sumSqr;
        }
        return true;
    }
};
