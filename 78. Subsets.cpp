class Solution {
public:
    vector<vector<int>> combine2(vector<int>& nums, int n, int k) {
        vector<vector<int>> res;
        if (n < k || k == 0 || n == 0)
            return res;
        else if (k == 1)
        {
            vector<int> tmp_vec(1);
		    for (int i = 0; i < n; ++i)
		    {
			    tmp_vec[0] = nums[i];
			    res.push_back(tmp_vec);
		    }
		    return res;
        }
        else
        {
            res = combine2(nums, n - 1, k);
            vector<vector<int>> tmp_res = combine2(nums, n - 1, k - 1);
            for (int j = 0; j < tmp_res.size(); j++)
                tmp_res[j].push_back(nums[n - 1]);
            res.insert(res.end(), tmp_res.begin(), tmp_res.end());
            return res;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res, tmp_res;
        vector<int> tmp_vec;
        res.push_back(tmp_vec);
        for (int i = 1; i <= nums.size(); i++)
        {
            tmp_res = combine2(nums, nums.size(), i);
            res.insert(res.end(), tmp_res.begin(), tmp_res.end());
        }
        return res;
    }
};