class Solution {
public:
    
    vector<vector<string>> partition(string s) 
    {
        vector<string> pp;
        helper(s, 0, pp, "");
        return res;
    }
    
    void helper(string& s, int bi, vector<string> pp, string prev)
    {
        if (bi == s.size())
        {
            if (pp.size() > 0 && prev == "")
                res.push_back(pp);
            return;
        }
        
        //judge if the string is palindrome    
        prev.push_back(s[bi]);
        bool flag = true;
        for (int i = 0; i < prev.size() / 2; i++)
        {
            if (prev[i] != prev[prev.size() - 1 - i])
            {
                flag = false;
                break;
            }
        }
        
        //keep searching wihtout pushing the string to the vector
        helper(s, bi + 1, pp, prev);

        //push the string to the vector and continue
        if (flag == true)
        {
            pp.push_back(prev);
            helper(s, bi + 1, pp, "");
        }
    }
    
    //data
    vector<vector<string>> res;
};