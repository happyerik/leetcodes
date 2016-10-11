class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++)
            dp[i].resize(n);
        
        bool flag = true;
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0 && flag == true)
                dp[i][0] = 1;
            else
            {
                dp[i][0] = 0;
                flag = false;
            }
        }
        
        flag = true;
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 0 && flag == true)
                dp[0][i] = 1;
            else
            {
                dp[0][i] = 0;
                flag = false;
            }
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else
                    dp[i][j] = 0;
            }
        }
        
        return dp[m-1][n-1];
    }
};