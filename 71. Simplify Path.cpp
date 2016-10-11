class Solution {
public:
    string simplifyPath(string path) 
    {
        deque<string> ds;
        string ts = "/";
        int flag = 0;
        for (int i = 0; i < path.size(); i++)
        {
            if (flag == 0)
            {
                if (path[i] == '/')
                {
                    //ts.push_back(path[i]);
                    flag = 1;
                }
            }
            else if (flag == 1)
            {
                if (path[i] == '/')
                    continue;
                else
                {
                    ts.push_back(path[i]);
                    flag = 2;
                }
            }
            else
            {
                if (path[i] == '/')
                {
                    if (ts == "/..")
                    {
                        if (!ds.empty())
                            ds.pop_back();
                    }
                    else if (ts == "/.")
                    {
                        //
                    }
                    else
                    {
                        ds.push_back(ts);
                    }
                    
                    ts = "/";
                    flag = 1;
                }
                else
                {
                    ts.push_back(path[i]);
                }
            }
        }
        
        if (ts == "/..")
        {
            if (ds.empty())
                return "/";
            else
                ds.pop_back();
        }
        else if (ts == "/.")
        {
            //
        }
        else if (ts != "/")
        {
            ds.push_back(ts);
        }
        
        if (ds.empty())
            return "/";
        else
        {
            string res = "";
            while (!ds.empty())
            {
                res += ds.front();
                ds.pop_front();
            }
            return res;
        }
    }
};

//version -2
class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> ss; // 记录路径名
        for(int i = 0; i < path.size(); )
        {
            // 跳过斜线'/'
            while(i < path.size() && '/' == path[i])
                ++ i;
            // 记录路径名
            string s = "";
            while(i < path.size() && path[i] != '/')
                s += path[i ++];
            // 如果是".."则需要弹栈，否则入栈
            if(".." == s && !ss.empty())
                ss.pop();
            else if(s != "" && s != "." && s != "..")
                ss.push(s);
        }
        // 如果栈为空，说明为根目录，只有斜线'/'
        if(ss.empty())
            return "/";
        // 逐个连接栈里的路径名
        string s = "";
        while(!ss.empty())
        {
            s = "/" + ss.top() + s;
            ss.pop();
        }
        return s;
    }
};