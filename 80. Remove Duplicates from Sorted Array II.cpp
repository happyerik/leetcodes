class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, prev;
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                nums[j++] = nums[i];
                prev = nums[i];
                count = 1;
            }
            else
            {
                if (nums[i] == prev)
                {
                    count++;
                    if (count > 2)
                    {
                        //count = 0;
                        continue;
                    }
                    else
                    {
                        nums[j++] = nums[i];
                    }
                }
                else
                {
                    nums[j++] = nums[i];
                    prev = nums[i];
                    count = 1;
                }
            }
        }
        return j;
    }
};