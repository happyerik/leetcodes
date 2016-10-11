class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        int a = 0, b = 0;
        int i1 = 0, i2 = 0;
        while (i1 < version1.size() || i2 < version2.size())
        {
            while (i1 < version1.size() && version1[i1] != '.')
            {
                a = a * 10 + version1[i1] - '0';
                i1++;
            }
            while (i2 < version2.size() && version2[i2] != '.')
            {
                b = b * 10 + version2[i2] - '0';
                i2++;
            }
            if (a > b)
                return 1;
            else if (a < b)
                return -1;
            else
            {
                a = 0;
                b = 0;
            }
            i1++;
            i2++;
        }
        return 0;
    }
};