class Solution {
public:
    bool helper(string& s1, string& s2, string& s3, int i1, int i2, int i3)
    {
        if (i3 > s3.size())
            return false;
        if (i1 == s1.size() && i2 == s2.size() && i3 == s3.size())
            return true; 
        
        bool flag1 = false;
        if (i1 < s1.size() && s1[i1] == s3[i3])
            flag1 = helper(s1, s2, s3, i1+1, i2, i3+1);
            
        bool flag2 = false;
        if (i2 < s2.size() && s2[i2] == s3[i3])
            flag2 = helper(s1, s2, s3, i1, i2+1, i3+1);
            
        bool flag3 = false;//helper(s1, s2, s3, i1, i2, i3+1);
        
        return flag1 || flag2 || flag3;
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        int m = s1.size();
        int n = s2.size();
        if(m+n != s3.size())
            return false;
        
        vector<vector<bool> > path(m+1, vector<bool>(n+1, false));
        for(int i = 0; i < m+1; i ++)
        {
            for(int j = 0; j < n+1; j ++)
            {
                if(i == 0 && j == 0)
                // start
                    path[i][j] = true;
                else if(i == 0)
                    path[i][j] = path[i][j-1] && (s2[j-1]==s3[j-1]);
                else if(j == 0)
                    path[i][j] = path[i-1][j] && (s1[i-1]==s3[i-1]);
                else
                    path[i][j] = (path[i][j-1] && (s2[j-1]==s3[i+j-1])) || (path[i-1][j] && (s1[i-1]==s3[i+j-1]));
            }
        }
        return path[m][n];
        
    }
};