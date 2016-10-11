class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> rf, cf;
        rf.resize(m, false);
        cf.resize(n, false);
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rf[i] = true;
                    cf[j] = true;
                }
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rf[i] == true || cf[j] == true)
                    matrix[i][j] = 0;
            }
        }
    }
};