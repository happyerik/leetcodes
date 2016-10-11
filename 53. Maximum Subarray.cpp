class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp_sum = 0, res = INT_MIN;
        
        //find the first positive number
        int i = 0;
        while (nums[i] < 0 && i < nums.size())
        {
            res = max(res, nums[i]);
            i++;
        }
        
        //calculate the maximum value
        for (; i < nums.size(); i++)
        {
            tmp_sum += nums[i];
            
            if (tmp_sum < 0)
            {
                tmp_sum = 0;
                continue;
            }
            else
            {
                res = max(res, tmp_sum);
            }
        }
        
        return res;
    }
};