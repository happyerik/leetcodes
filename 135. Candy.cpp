class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int i;
        int n = ratings.size();
        int result = 0;
        vector<int> count(n);
        
        //每一个人至少一个糖果
        for(i = 0; i < n; i++)
            count[i] = 1;
        
        // 左右各扫描一遍
        //从左向右扫描
        for(i = 1; i < n; i++)
        {
            //如果第i个小孩等级比第i-1个高，那么i的糖数目等于i-1的糖数目+1
            if(ratings[i] > ratings[i-1])
                count[i] = count[i-1] + 1;
        }
        
        //从右向左扫描
        for(i = n-2; i >= 0; i--)
        {
            //如果第i个的小孩的权值比i+1个小孩高,但是糖的数目却小或者相等，那么i的糖数目等于i+1的糖数目+1。
            if(ratings[i] > ratings[i+1] && count[i] <= count[i+1])
                count[i] = count[i+1] + 1;
        }
        //统计糖果数量
        for(i = 0;i < n;i++)
            result += count[i];
        return result;
    }
};