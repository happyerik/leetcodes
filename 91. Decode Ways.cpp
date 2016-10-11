class Solution {
public:
    int numDecodings(string s) 
    {
        if (s == "" || s == "0")
            return 0;
        
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        if (s[0] == '0')
            dp[1] = 0;
        else 
            dp[1] = 1;
        for (int i = 2; i < s.size() + 1; i++)
        {
            int tmp1 = s[i-1] - '0', tmp2 = s[i-2] - '0';
            if (tmp1 == 0)
            {
                if (tmp2 > 2 || tmp2 == 0)
                    return 0;
                else
                    dp[i] = dp[i - 2];
            }
            else
            {
                if ((tmp1 <= 6 && tmp2 > 0 && tmp2 <= 2) || (tmp1 <= 9 && tmp2 == 1))
                {
                    dp[i] = dp[i - 2] + dp[i - 1];
                }
                else
                    dp[i] = dp[i - 1];
            }
        }
        
        return dp[s.size()];
    }
};