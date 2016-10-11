//version -1
class Solution {
public:
    bool ifexistone(const vector<char>& a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == '1')
            {
                return true;
            }
        }
        return false;
    }
    int calc_continuous_num(const vector<char>& a)
    {
        int re = 0;
        int tmp_val = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == '1')
            {
                tmp_val++;
            }
            else
            {
                re = max(re, tmp_val);
                tmp_val = 0;
            }
        }
        re = max(re, tmp_val);
        return re;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row_num = matrix.size();
        if (row_num == 0)
            return 0;
        int col_num = matrix[0].size();
        int re = 0;
        
        //scan all rows
        for (int i = 0; i < row_num; i++)
        {
            vector<char> tmp_row = matrix[i];
            int j = i;
            while (ifexistone(tmp_row) && j < row_num)
            {
                int tmp_val = calc_continuous_num(tmp_row) * (j - i + 1);
                re = max(tmp_val, re);
                j++;
                for (int ii = 0; ii < col_num && j < row_num; ii++)
                    tmp_row[ii] = tmp_row[ii] & matrix[j][ii];
            }
        }
        
        return re;
    }
};

//version -2
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int H = matrix.size(), W = matrix[0].size();
        int height[W+1];
        int i, j , MAX = 0, leftarea = 0, rightarea = 0;
        stack<int> st;
        for(i = 0; i <= W; height[i] = 0, ++i);
        for(i = 0; i < H; ++i){
            while(!st.empty()) st.pop();
            for(j = 0; j < W; ++j){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            for(int j = 0; j <= W; ++j){
                while(!st.empty() && height[st.top()] > height[j]){
                    int tmp = st.top();
                    st.pop();
                    leftarea = (st.empty() ? tmp + 1 : tmp - st.top()) * height[tmp];
                    rightarea = (j - tmp - 1) * height[tmp];
                    if((leftarea + rightarea) > MAX) MAX = (leftarea + rightarea);
                }
                st.push(j);
            }
        }
        return MAX;
    }
};