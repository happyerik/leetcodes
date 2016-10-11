class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n < k || k == 0 || n == 0)
            return res;
        else if (k == 1)
        {
            vector<int> tmp_vec(1);
		    for (int i = 1; i <= n; ++i)
		    {
			    tmp_vec[0] = i;
			    res.push_back(tmp_vec);
		    }
		    return res;
        }
        else
        {
            res = combine(n - 1, k);
            vector<vector<int>> tmp_res = combine(n - 1, k - 1);
            for (int j = 0; j < tmp_res.size(); j++)
                tmp_res[j].push_back(n);
            res.insert(res.end(), tmp_res.begin(), tmp_res.end());
            return res;
        }
    }
};