class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else
        {
            int tmp1 = 1, tmp2 = 2;
            for (int i = 3; i <= n; i++)
            {
                int tmp = tmp2;
                tmp2 += tmp1;
                tmp1 = tmp;
            }
            return tmp2;
        }
    }
};