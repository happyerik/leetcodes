//version -1 TLC
class Solution {
public:
    bool helper(string& s, unordered_set<string>& wordDict, int bi, string prev)
    {
        if (bi == s.size())
        {
            if (prev == "")
                return true;
            else
                return false;
        }
        
        prev.push_back(s[bi]);
        bool flag1, flag2;
        flag1 = helper(s, wordDict, bi+1, prev);
        if (wordDict.find(prev) == wordDict.end())
            return flag1;
        else
        {
            prev = "";
            flag2 = helper(s, wordDict, bi+1, prev);
            return flag1 || flag2;
        }
    }
    
    bool wordBreak(string s, unordered_set<string>& wordDict) 
    {
        //vector<vector<bool>> flags;
        //flags.resize(s.size());
        //for (int i = 0; i < s.size(); i++)
        //    flags[i].resize(s.size() - i);
        
        stack<int> cand;
        for (int i = 0; i < s.size(); i++)
        {
            string ts = s.substr(0, i+1);
            if (wordDict.find(ts) != wordDict.end())
            {
                if (i == s.size() - 1)
                    return true;
                cand.push(i+1);
            }
                
        }
        
        while (!cand.empty())
        {
            int curIndex = cand.top();
            cand.pop();
            
            for (int i = curIndex; i < s.size(); i++)
            {
                string ts = s.substr(curIndex, i-curIndex+1);
                if (wordDict.find(ts) != wordDict.end())
                {
                    if (i == s.size() - 1)
                        return true;
                    cand.push(i+1);
                }
            }
        }
        
        return false;
    }
};

//version -2
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) 
    {
        vector<bool> flags(s.size(), false);
        for (int i = 0; i < s.size(); i++)
        {
            string ts = s.substr(0, i+1);
            if (wordDict.find(ts) != wordDict.end())
                flags[i] = true;
            else
            {
            	//san all the possible ways!!!
                for (int j = 0; j < i; j++)
                {
                    ts = s.substr(j+1, i-j);
                    if (flags[j] == true && wordDict.find(ts) != wordDict.end())
                        flags[i] = true;
                }
            }
        }
        
        return flags[s.size() - 1];
    }
};