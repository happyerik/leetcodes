class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high && nums[low] >= nums[high])
        {
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[low])   // mid is in second part
                high = mid;
            else if(nums[mid] == nums[low])
                low++;   //important operation!!!
            else
                low = mid+1;
        }
        return nums[low];
    }
};