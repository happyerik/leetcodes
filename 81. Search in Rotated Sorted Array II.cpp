class Solution {
public:
    int binarysearch(vector<int>& nums, int target, int bi, int ei)
    {
        if (bi > ei)
            return -1;
        else
        {
            int mid = bi + (ei - bi) / 2;
            if (nums[mid] < target)
            {
                return binarysearch(nums, target, mid + 1, ei);
            }
            else if(nums[mid] > target)
            {
                return binarysearch(nums, target, bi, mid - 1);
            }
            else
                return mid;
        }
    }
    
    bool search(vector<int>& nums, int target) 
    {
        //find the pivot index
        int pi = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= nums[i - 1])
                pi++;
            else
                break;
        }
        
        int fi;
        if (target < nums[0])
            fi = binarysearch(nums, target, pi + 1, nums.size() - 1);
        else
            fi = binarysearch(nums, target, 0, pi);
        return fi == -1 ? false : true;
    }
};