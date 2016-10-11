//µÝ¹é°æ TLE
void Distinct_Subsequences(string& s, string& t, int si, int ti, int& res)
{
	if (ti == t.size())
	{
		res++;
		return;
	}

	if (si >= s.size())
		return;

	if (s[si] == t[ti])
		Distinct_Subsequences(s, t, si + 1, ti + 1, res);
	Distinct_Subsequences(s, t, si + 1, ti, res);
}

//¶¯Ì¬¹æ»®°æ OK
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() == 0 && t.size() == 0)
            return 1;
        if (s.size() < t.size())
            return 0;
        vector<vector<int>> dp;
        dp.resize(s.size() + 1);
        for (int i = 0; i < dp.size(); i++)
            dp[i].resize(t.size() + 1);
        
        for (int i = 0; i < s.size(); i++)
            dp[i][0] = 1;
            
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};