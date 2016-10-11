class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        else
        {
            int l = 0, r = x;
            int mid;
            long long tmp;
            while (l <= r)
            {
                mid = l + (r - l) / 2;
                tmp = static_cast<long long>(mid) * static_cast<long long>(mid);
                if (tmp > static_cast<long long>(x))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            
            return l-1;
        }
    }
};