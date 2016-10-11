//Mine
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
        {
            if (n == INT_MIN)
                return 1.0 / (myPow(x, INT_MAX) * x);
            else
                return 1.0 / myPow(x, -n);
        }
        else if (n == 0)
            return 1.0;
        else if (n == 1)
            return x;
        else //n > 1
        {
            if (n & 1 == 1)
                return myPow(x, n - 1) * x;
            else
            {
                double tmp = myPow(x, n / 2);
                return tmp * tmp;
            }
        }
    }
};

//From Internet
class Solution {  
public:  
    double pow(double x, int n) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        if(n<0)  
        {  
            if(n==INT_MIN)  
                return 1.0 / (pow(x,INT_MAX)*x);  
            else  
                return 1.0 / pow(x,-n);  
        }  
        if(n==0)  
            return 1.0;  
        double ans = 1.0 ;  
        for(;n>0; x *= x, n>>=1)  
        {  
            if(n&1>0)  
                ans *= x;  
        }  
        return ans;  
    }  
};  