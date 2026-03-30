class Solution {
private:
    int sumOfSquares(int n)
    {
        int sum = 0;
        while(n != 0)
        {
            int d = n%10;
            sum += (d * d);
            n = n/10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> numSet;

        while(n != 1)
        {
            n = sumOfSquares(n);
            if(n != 1 && numSet.count(n)) // It will loop around in this set
                return false;
            numSet.insert(n);
        }
        return true;
    }
};
