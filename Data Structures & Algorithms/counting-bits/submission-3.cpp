class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0)
            return {0};
        vector<int> out;
        out.push_back(0);
        out.push_back(1);

        if(n == 1)
            return out;

        int curP = 1;
        for(auto i = 2; i <= n; ++i)
        {
            if(i == curP * 2)
                curP *=2;
            out.push_back(1 + out[i-curP]);
        }
        return out;
    }
};
