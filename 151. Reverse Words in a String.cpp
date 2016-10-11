class Solution {
public:
    void reverseWords(string &s) 
    {
        int sz = s.size();
        if (sz == 0)
            return;
            
        //pre-processing
        for (int i = sz - 1; i > 0; i--)
        {
            if (s[i] == ' ' && s[i-1] == ' ')
                s.erase(i, 1);
        }
        if (s[0] == ' ')
            s.erase(0, 1);
        if (s.size() > 0 && s[s.size() - 1] == ' ')
            s.erase(s.size() - 1, 1);
        
        //main process
        reverse(s.begin(), s.end());
        int bi = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                continue;
            else
            {
                
                reverse(s.begin() + bi, s.begin() + i);
                bi = i+1;
            }
        }
        reverse(s.begin() + bi, s.end());
        return;
    }
};