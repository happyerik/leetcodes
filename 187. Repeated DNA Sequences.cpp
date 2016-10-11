//version -1  maximum complexity is o(nlogn)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        if (s.size() < 10)
            return res;
        map<string, int> ms;
        for (int i = 0; i <= s.size() - 10; i++)
        {
            string tmps = s.substr(i, 10);
            if (ms.count(tmps) != 0)
                ms[tmps]++;
            else
                ms[tmps] = 1;
        }
        
        for (map<string, int>::iterator it = ms.begin(); it != ms.end(); it++)
        {
            if (it->second >= 2)
                res.push_back(it->first);
        }
        
        return res;
    }
    vector<string> res;
};

//version -2
class Solution {
public:
    int getVal(char ch) {
        if (ch == 'A') return 0;
        if (ch == 'C') return 1;
        if (ch == 'G') return 2;
        if (ch == 'T') return 3;
    }
    
    vector<string> findRepeatedDnaSequences(string s) 
    {
        set<string> st;
        vector<string> res;
        string str;
        if (s.length() < 10 || s == "") return res;
        int mp[1024*1024] = {0};
        unsigned int val = 0;
        for (int i = 0; i < 9; ++i) 
        {
            val <<= 2;
            val |= getVal(s[i]);
        }
        for (int i = 9; i < s.length(); ++i) 
        {
            val <<= 14;
            val >>= 12;
            val |= getVal(s[i]);
            ++mp[val];
            if (mp[val] > 1) 
            {
                str = s.substr(i-9, 10);
                st.insert(str);
            }
        }
        for (set<string>::iterator i = st.begin(); i != st.end(); ++i) 
        {
            res.push_back(*i);
        }
        return res;
    }
};