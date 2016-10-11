//version -1 O(N) complexity
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        if (nums.size() == 1)
            return 0;
        int i = 0;
        for (; i < nums.size(); i++)
        {
            if (i == 0)
            {
                if (nums[i] > nums[i+1])
                    break;
            }
            else if (i == nums.size() - 1)
            {
                if (nums[i] > nums[i-1])
                    break;
            }
            else
            {
                if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) 
                    break;
            }
        }
        return i;
    }
};

//version -2 binary search
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size()-1;
        while(low < high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[mid+1])
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};