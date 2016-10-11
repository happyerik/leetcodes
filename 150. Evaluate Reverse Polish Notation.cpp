class Solution {
public:
    int str2int(string& str)
    {
        int res = 0;
        int i = 0;
        
        int flag = 1;
        if (str[i] == '+')
            i = 1;
        else if (str[i] == '-')
        {
            i = 1;
            flag = -1;
        }
        else
            i = 0;
        
        for (; i < str.size(); i++)
            res = res * 10 + (str[i] - '0');
        
        return flag * res;
    }
    int evalRPN(vector<string>& tokens) 
    {
        if (tokens.size() == 0)
            return 0;
        stack<int> si;
        int left, right;
        for(int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                si.push(str2int(tokens[i]));
            else
            {
                right = si.top();
                si.pop();
                left = si.top();
                si.pop();
                if (tokens[i] == "+")
                    si.push(left+right);
                else if (tokens[i] == "-")
                    si.push(left-right);
                else if (tokens[i] == "*")
                    si.push(left*right);
                else if (tokens[i] == "/")
                    si.push(left/right);
            }
        }
        
        return si.top();
    }
};