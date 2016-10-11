class Solution {
public:
    int trap(vector<int>& height) 
    {
        if (height.size() < 3)
            return 0;
        int max_val = INT_MIN, max_index;
        
        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] > max_val)
            {
                max_val = height[i];
                max_index = i;
            }
        }
        
        int res = 0;
        int cur_top = height[0];
        for (int i = 0; i < max_index; i++)
        {
            if (height[i] < cur_top)
            {
                res += cur_top -height[i];
            }
            else
                cur_top = height[i];
        }
        
        cur_top = height[height.size() - 1];
        for (int i = height.size() - 1; i > max_index; i--)
        {
            if (height[i] < cur_top)
            {
                res += cur_top -height[i];
            }
            else
                cur_top = height[i];
        }
        
        return res;
    }
};