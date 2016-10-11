class Solution {
public:
    bool isPalindrome(string s) 
    {
        if (s.size() == 0)
            return true;
        string tmp_s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                tmp_s.push_back(s[i]);
            else if (s[i] >= 'A' && s[i] <= 'Z')
                tmp_s.push_back(s[i] + 'a' - 'A');
            else if (s[i] >= '0' && s[i] <= '9')
                tmp_s.push_back(s[i]);
            else
                continue;
        }
        
        int len = tmp_s.size();
        for (int i = 0; i < len / 2; i++)
        {
            if (tmp_s[i] != tmp_s[len - 1 - i])
                return false;
        }
        return true;
    }
};