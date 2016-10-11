class Solution {
public:
    vector<vector<int>> combine3(vector<int>& nums, int n, int k, bool flag) 
    {
        vector<vector<int>> res;
        if (n < k || k == 0 || n == 0)
            return res;
        else if (k == 1 && n == nums.size())
        {
            vector<int> tmp_vec(1);
            int prev = nums[0];
            tmp_vec[0] = nums[0];
            res.push_back(tmp_vec);
		    for (int i = 1; i < n; ++i)
		    {
			    if (nums[i] == prev) 
			        continue;
			    
			    tmp_vec[0] = nums[i];
			    prev = nums[i];
			    res.push_back(tmp_vec);
		    }
		    return res;
        }
        else if (k == 1 && n < nums.size())
        {
            int nn = n;
            if (flag == false)
            {
                while (nums[nn - 1] == nums[n] && nn > 0)
                {
                    nn--;
                }    
            }
            if (nn == 0)
                return res;
            
            vector<int> tmp_vec(1);
            int prev = nums[0];
            tmp_vec[0] = nums[0];
            res.push_back(tmp_vec);
		    for (int i = 1; i < nn; ++i)
		    {
			    if (nums[i] == prev) 
			        continue;
			    
			    tmp_vec[0] = nums[i];
			    prev = nums[i];
			    res.push_back(tmp_vec);
		    }
		    return res;
        }
        else
        {
            vector<vector<int>> tmp_res;
            if (flag == false && nums.size() > n && nums[n - 1] == nums[n])
                tmp_res.clear();
            else
                tmp_res = combine3(nums, n - 1, k - 1, true); 
            for (int j = 0; j < tmp_res.size(); j++)
                tmp_res[j].push_back(nums[n - 1]);
                
            res = combine3(nums, n - 1, k, false);
            res.insert(res.end(), tmp_res.begin(), tmp_res.end());
            return res;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res, tmp_res;
        vector<int> tmp_vec;
        res.push_back(tmp_vec);
        for (int i = 1; i <= nums.size(); i++)
        {
            tmp_res = combine3(nums, nums.size(), i, false);
            res.insert(res.end(), tmp_res.begin(), tmp_res.end());
        }
        return res;
    }
};

//from Internet (great!!!)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
	{
        vector<int> path;
        vector<vector<int>> result;
        result.push_back(path);
        sort(nums.begin(),nums.end());
        helper(nums,0,path,result);
        return result;
    }

    void helper(vector<int> &nums,int pos,vector<int>& path,vector<vector<int>> &result)
    {
        if(pos == nums.size())
            return ;

        for(int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            result.push_back(path);
            helper(nums,i + 1,path,result);
            path.pop_back();
            while(nums[i] == nums[i+1]) i++;
        }
    }
};