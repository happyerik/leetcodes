//version -1 (TLE)
class Solution {
public:
    bool ifPalindrome(string& str)
    {
        for (int i = 0; i < str.size() / 2; i++)
        {
            if (str[i] != str[str.size() - 1 - i])
                return false;
        }
        return true;
    }
    
    int minCut(string s) 
    {
        int res = 0;
        int sz = s.size();
        if (ifPalindrome(s))
            return res;
        queue<int> qi;
        for (int i = 0; i < sz; i++)
        {
            string tmps = s.substr(i, sz - i);
            if (ifPalindrome(tmps))
                qi.push(i);
        }
        res++;
        while (!qi.empty())
        {
            int qiz = qi.size();
            for (int i = 0; i < qiz; i++)
            {
                int ti = qi.front();
                qi.pop();
                string tmps = s.substr(0, ti);
                if (ifPalindrome(tmps))
                    return res;
                else
                {
                    for (int j = 0; j < tmps.size(); j++)
                    {
                        string tmps = s.substr(j, ti - j);
                        if (ifPalindrome(tmps))
                            qi.push(j);
                    }
                }
            }
            res++;
        }
        return res;
    }
};

//version -2
class Solution {
public:
    int minCut(string s) 
    {
        int n = s.size();
        vector<vector<bool> > isPalin(n, vector<bool>(n, false));
        vector<int> min(n+1, -1); //min cut from end
        
        for(int i = 0; i < n; i ++)
        {
            isPalin[i][i] = true;
        }
        
        for(int i = n-1; i >= 0; i --)
        {
            min[i] = min[i+1] + 1;
            for(int j = i+1; j < n; j ++)
            {
                if(s[i] == s[j])
                {
                    if(j == i+1 || isPalin[i+1][j-1] == true)
                    {
                        isPalin[i][j] = true;
                        if(j == n-1)
                            min[i] = 0;
                        else if(min[i] > min[j+1]+1)
                            min[i] = min[j+1] + 1;
                    }
                }
            }
        }
        
        return min[0];
    }
};