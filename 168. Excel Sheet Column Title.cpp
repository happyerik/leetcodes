class Solution {
public:
    string convertToTitle(int n) 
    {
        string res = "";
        int tmp = 0;
        
        while (n > 0)
        {
            n--;
            tmp = n % 26;
            res.push_back((n % 26) + 'A');
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};