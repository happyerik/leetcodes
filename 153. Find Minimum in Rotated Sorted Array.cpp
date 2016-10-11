class Solution {
public:
    int findPos(vector<int>& nums)
    {
	    int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high && nums[low] >= nums[high])
        {
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[low])   // mid is in second part
                high = mid;
            else if(nums[mid] == nums[low])
                low ++;   //important operation!!!
            else
                low = mid+1;
        }
        return low;
    }
    
    int findMin(vector<int>& nums) {
        int pi = findPos(nums);
        return nums[pi];
    }
};