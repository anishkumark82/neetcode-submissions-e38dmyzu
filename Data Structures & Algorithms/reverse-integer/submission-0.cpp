class Solution {
public:
    int reverse(int x) {
        int maxVal = INT_MAX/10;
        int minVal = INT_MIN/10;
        int rev = 0;
        while(x != 0)
        {
            if(rev > maxVal || rev < minVal)
                return 0;
            int d = x % 10;
            x = x / 10;
            rev = (rev * 10) + d;  
        }
        return rev;
    }
};
