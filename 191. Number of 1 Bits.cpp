class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        uint32_t x = 1;
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((n & x) != 0)
                res++;
            x = (x << 1);
        }
        return res;
    }
};