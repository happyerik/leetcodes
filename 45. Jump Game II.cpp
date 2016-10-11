class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        int curMax = 0;
        int curRch = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(curRch < i)
            {
                ret++;
                curRch = curMax;
                if (curRch >= nums.size() - 1)
                    break;
            }
            curMax = max(curMax, nums[i]+i);
        }
        return ret;
    }
};