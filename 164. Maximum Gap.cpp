//version -1 o(nlogn)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < nums.size(); i++)
            res = max(res, nums[i] - nums[i-1]);
        return res;
    }
};

//version -2 //based on fast sorting idea
class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        if (nums.size() < 2)
            return 0;
        else if (nums.size() == 2)
            return abs(nums[1] - nums[0]);
        else
        {
            vector<int> left, right;
            int left_cand = INT_MAX, right_cand = INT_MAX;
            for (int i = 1; i < nums.size(); i++)
            {
                int tmp_val = nums[i] - nums[0];
                if (tmp_val < 0)
                {
                    left.push_back(nums[i]);
                    left_cand = min(left_cand, -tmp_val);
                }
                else
                {
                    right.push_back(nums[i]);
                    right_cand = min(right_cand, tmp_val);
                }
            }
            if (left.size() == 0)
                left_cand = 0;
            if (right.size() == 0)
                right_cand = 0;
            left_cand = max(left_cand, maximumGap(left));
            right_cand = max(right_cand, maximumGap(right));
            return max(left_cand, right_cand);
        }
    }
};

//Suppose there are N elements and they range from A to B.
//Then the maximum gap will be no smaller than ceiling[(B - A) / (N - 1)]
//Let the length of a bucket to be len = ceiling[(B - A) / (N - 1)], then we will have at most num = (B - A) / len + 1 of bucket
//for any number K in the array, we can easily find out which bucket it belongs by calculating loc = (K - A) / len and therefore maintain the maximum and minimum elements in each bucket.
//Since the maximum difference between elements in the same buckets will be at most len - 1, so the final answer will not be taken from two elements in the same buckets.
//For each non-empty buckets p, find the next non-empty buckets q, then q.min - p.max could be the potential answer to the question. Return the maximum of all those values.

//version -3  bucket-sort
//48ms  
struct Bucket {  
    int local_min;  
    int local_max;  
    int local_volumn;  
    Bucket():local_volumn(0){};  
};  
class Solution {  
public:  
    int maximumGap(vector<int> &num) {  
        if (num.size() < 2) return 0;  
        if (num.size() == 2) return num[0] - num[1] > 0 ? num[0] - num[1] : num[1] - num[0];  
        int min = INT_MAX;  
        int max = INT_MIN;  
        int max_gap = 0;  
        for (int i = 0; i < num.size(); ++i) {  
            if (num[i] < min) min = num[i];  
            if (num[i] > max) max = num[i];  
        }  
        int bucket_length = (max - min) / (num.size() - 1) + 1; //maximum gap >= ceiling[(B - A) / (N - 1)]  
        int bucket_count = (max - min) / bucket_length + 1;  
        vector<Bucket> bucket(bucket_count, Bucket());  
        for (int i = 0; i < num.size(); ++i) {  
            int index = (num[i] - min) / bucket_length;  
            if (bucket[index].local_volumn == 0) //NOTE1: 如果桶内最多只有一个元素，那么max 和 min都赋值为这个元素。  
                bucket[index].local_max = bucket[index].local_min = num[i];  
            else if (num[i] > bucket[index].local_max)  
                bucket[index].local_max = num[i];  
            else if (num[i] < bucket[index].local_min)  
                bucket[index].local_min = num[i];  
            bucket[index].local_volumn++;  
  
        }  
        int previous = 0; //NOTE2: 用previous来跳过空桶,第0个桶必然不是空桶，所以previous可以从0开始取值。  
        for (int i = 1; i < bucket.size(); ++i) {  
            if (bucket[i].local_volumn == 0) continue;  
            if (bucket[i].local_min  - bucket[previous].local_max > max_gap)  
                max_gap = bucket[i].local_min  - bucket[previous].local_max;  
            previous = i;  
        }  
        return max_gap;  
    }  
}; 