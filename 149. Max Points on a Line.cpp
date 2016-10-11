/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) 
    {
        if(points.empty())
            return 0;
        else if(points.size() == 1)
            return 1;
            
        int ret = 0;
        for(int i = 0; i < points.size(); i ++)
        {
            //start point
            int curmax = 1; //points[i] itself
            unordered_map<double, int> kcnt;    // slope_k count
            int vcnt = 0;   // vertical count
            int dup = 0;    // duplicate added to curmax
            for(int j = 0; j < points.size(); j ++)
            {
                if(j != i)
                {
                    double deltax = points[i].x - points[j].x;
                    double deltay = points[i].y - points[j].y;
                    if(deltax == 0 && deltay == 0)
                        dup ++;
                    else if(deltax == 0)
                    {
                        if(vcnt == 0)
                            vcnt = 2;
                        else
                            vcnt ++;
                        curmax = max(curmax, vcnt);
                    }
                    else
                    {
                        double k = deltay / deltax;
                        if(kcnt[k] == 0)
                            kcnt[k] = 2;
                        else
                            kcnt[k]++;
                        curmax = max(curmax, kcnt[k]);
                    }
                }
            }
            ret = max(ret, curmax + dup);
        }
        return ret;
    }
};