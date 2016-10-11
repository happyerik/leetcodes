//1- TLC
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0)
            return 0;
        else
        {
            long long res = static_cast<long long>(heights[0]); //initialization
            for (int i = heights.size() - 1; i >= 0; i--)
            {
                long long min_val = static_cast<long long>(heights[i]);
                res = max(res, (long long) heights[i]);
                
                for (int j = i - 1; j >= 0; j--)
                {
                    min_val = min(static_cast<long long>(heights[j]), min_val);
                    if (res > min_val * static_cast<long long>(i + 1))
                        break;
                    else
                        res = max(res, min_val * static_cast<long long>(i - j + 1));
                }
            }
            
            return static_cast<int>(res);
        }
    }
};

//2- TLC
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0)
            return 0;
        else
        {
            int res = 0;
            for (int i = 0; i < heights.size(); i++)
            {
                int tmp_val = 1;
                int left = i - 1, right = i + 1;
                while (left >= 0)
                {
                    if (heights[i] <= heights[left])
                        tmp_val++;
                    else
                        break;
                    left--;
                }
                while (right < heights.size())
                {
                    if (heights[i] <= heights[right])
                        tmp_val++;
                    else
                        break;
                    right++;
                }
                res = max(res, heights[i] * tmp_val);
            }
            
            return res;
        }
    }
};

//3- from Internet
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) 
            return 0; 
        stack<int> st;
        int MAX = 0;
        heights.push_back(0);
        int leftarea = 0, rightarea = 0;
        for(int i = 0; i < heights.size(); ++i)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int tmp = st.top();
                st.pop();
                
                //以tmp为高度，tmp所在柱以及向左延伸出来的矩形面积
                leftarea = ((st.empty() ? tmp + 1 : tmp) - st.top()) * heights[tmp]; 
                
                //以tmp为高度，向右边延伸出来的矩形面积
                rightarea = (i - tmp - 1) * heights[tmp];
                
                if((leftarea + rightarea) > MAX) MAX = (leftarea + rightarea);
            }
            st.push(i);
        }
        return MAX;
    }
};