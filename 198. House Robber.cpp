class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;
        vector<int> dp1(nums.size(), 0), dp2(nums.size(), 0);
        dp1[0] = nums[0];
        dp2[0] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            dp1[i] = nums[i] + dp2[i-1];
            dp2[i] = max(dp1[i-1], dp2[i-1]);
        }
        return max(dp1[nums.size() - 1], dp2[nums.size() - 1]);
    }
};