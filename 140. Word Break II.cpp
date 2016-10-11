//version -1 (TLE!!!)
class Solution {
public:
    void helper(string& s, unordered_set<string>& wordDict, int bi, string ls, string cs)
    {
        if (bi == s.size())
        {
            if (ls == "")
                res.push_back(cs.substr(0, cs.size() - 1));
            return;    
        }
        
        ls.push_back(s[bi]);
        helper(s, wordDict, bi+1, ls, cs);
        if (wordDict.count(ls) != 0)
        {
            cs += ls + " ";
            ls = "";
            helper(s, wordDict, bi+1, ls, cs);
        }
    }
    
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
    {
        string ls = "", cs = "";
        helper(s, wordDict, 0, ls, cs);
        return res;
    }
    
    vector<string> res;
};

//version -2
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
    {
        //vector<string> res;
        vector<vector<int>> vvi(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            string ts = s.substr(0, i+1);
            if (wordDict.count(ts) != 0)
                vvi[i].push_back(0);
            for (int j = 0; j < i; j++)
            {
                if (wordDict.count(ts.substr(j+1, i-j)) != 0 && vvi[j].size() > 0)
                    vvi[i].push_back(j+1);
            }
        }
        
        //int curIndex = s.size() - 1;
        //cs = "";
        helper(s, vvi, s.size() - 1, "");
        return res;
    }
    
    void helper(string& s, vector<vector<int>>& vvi, int curIndex, string cs)
    {
        if (curIndex < 0 && cs.size() > 0)
        {
            res.push_back(cs.substr(0, cs.size()-1));
            return;
        }
        
        string ts = cs;
        for (int i = 0; i < vvi[curIndex].size(); i++)
        {
            int nextIndex = vvi[curIndex][i];
            cs = s.substr(nextIndex, curIndex - nextIndex + 1) + " " + cs;
            helper(s, vvi, vvi[curIndex][i]-1, cs);
            cs = ts;
        }
    }
    
    vector<string> res;
};