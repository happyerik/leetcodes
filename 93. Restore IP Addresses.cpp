class Solution {
public:
    void helper(string& s, int dep, int bi, string str)
    {
        if (dep == 4)
        {
            if (bi == s.size())
            {
                str.erase(str.end() - 1);
                res.push_back(str);
            }    
            return;
        }
        
        int tmp = 0;
        string tmp_s = "";
        while (bi < s.size())
        {
            tmp = tmp * 10 + (s[bi] - '0');
            if (tmp == 0)
            {
                tmp_s.push_back(s[bi]);
                helper(s, dep + 1, bi+1, str + tmp_s + ".");
                break;
            }
            else if (tmp > 0 && tmp <= 255)
            {
                tmp_s.push_back(s[bi]);
                helper(s, dep + 1, bi+1, str + tmp_s + ".");
            }
            else
            {
                break;
            }
            bi++;
        }
    }
    
    vector<string> restoreIpAddresses(string s) 
    {
        string str = "";
        helper(s, 0, 0, str);
        return res;
    }
    
    //data
    vector<string> res;
};