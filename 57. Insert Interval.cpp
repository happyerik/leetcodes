/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int binarysearch(vector<int>& nums, int target)
    {
        if (nums[0] > target)
            return -1;
        else if (nums[nums.size() - 1] < target)
            return nums.size();
        else
        {
            int bi = 0, ei = nums.size() - 1; 
            while (bi < ei)
            {
                int mid = bi + (ei - bi) / 2;
                if (nums[mid] > target)
                    ei = mid - 1;
                else
                    bi = mid + 1;
            }
            return bi;
        }
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
    {
        int sz = intervals.size();  
        vector<Interval> res;  
          
        for(int i=0; i<sz; i++) 
        {  
            if(intervals[i].end < newInterval.start) 
            {  
                res.push_back( intervals[i]);  
            } 
            else if( intervals[i].start > newInterval.end) 
            {  
                res.push_back(newInterval);  
                res.insert(res.end(), intervals.begin()+i, intervals.end());  
                return res;  
            } 
            else 
            {  
                newInterval.start = min(newInterval.start, intervals[i].start);  
                newInterval.end = max(newInterval.end, intervals[i].end);  
            }  
        }  
        res.push_back(newInterval);   
        return res;  
    }
};