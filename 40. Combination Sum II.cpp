class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        vector<vector<int>> result;
        helper(candidates,0,0,target,path,result);
        return result;
    }

    void helper(vector<int> &nums,int pos,int base,int target,vector<int> &path,vector<vector<int>> &result)
    {
        if (base == target)
        {
            result.push_back(path);
            return;
        }
        else if (base > target)
            return;
        else
        {
            for(int i = pos; i < nums.size(); i++)
            {
                path.push_back(nums[i]);
                helper(nums,i+1,base+nums[i],target,path,result);
                path.pop_back();
                while(nums[i]==nums[i+1]) 
                    i++;
            }
        }
    }
};