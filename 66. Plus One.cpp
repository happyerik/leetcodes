class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 0;
        vector<int> res(digits.size() + 1, 0);
        int dl = digits.size() - 1;
        for (int i = 0; i < digits.size(); i++)
        {
            if (i == 0)
            {
                res[i] = (digits[dl - i] + 1) % 10;
                flag = (digits[dl - i] + 1) / 10;
            }
            else
            {
                res[i] = (digits[dl - i] + flag) % 10;
                flag = (digits[dl - i] + flag) / 10;
            }
        }
        
        if (flag == 1)
        {
            res[dl + 1] = 1;
        }
        else
        {
            res.resize(digits.size());
        }
            
        reverse(res.begin(), res.end());
        return res;
    }
};