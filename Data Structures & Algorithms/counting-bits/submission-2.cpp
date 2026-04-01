class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0)
            return {0};
        if(n == 1)
            return {0,1};

        vector<int> out(n+1, 0);
        out[0] = 0;
        out[1] = 1;
        int tPow = 2;

        for(auto i = 2;i <= n; ++i)
        {
            if(i >= tPow)
                tPow *= 2;
            out[i] = 1 + out[i-(tPow/2)]; 
        }
        return out;
    }
};
