class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int res = 0;
        if (prices.size() < 2)
            return res;
        
        vector<int> ml(prices.size(), 0);
        vector<int> mr(prices.size(), 0);
        
        //maximum profit from 0 to i
        int minV = prices[0];
        ml[0] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            minV = min(minV, prices[i]);
            ml[i] = max(ml[i-1], prices[i] - minV);
        }
        
        //maximum profit from N-1 to i
        int maxV = prices[prices.size() - 1];
        mr[prices.size() - 1] = 0;
        for (int i = prices.size() - 2; i >= 0; i--)
        {
            maxV = max(maxV, prices[i]);
            mr[i] = max(mr[i+1], maxV - prices[i]);
        }
        
        for (int i = 0; i < prices.size(); i++)
            res = max(res, ml[i] + mr[i]);
        
        return res;
    }
};