class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for(auto i = 0; i < 32; ++i)
        {
            uint32_t b = (n >> i) & 0x1;
            res = res | (b << (31-i));
        }
        return res;
    }
};
