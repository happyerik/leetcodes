class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int bv = 0, sv = 0;
        int res = 0;
        while (bv < prices.size())
        {
            if (prices[bv+1] > prices[bv])
            {
                for (sv = bv + 1; sv < prices.size(); sv++)
                    res = max(res, prices[sv] - prices[bv]);
            }
            bv++;
        }
        return res;
    }
};