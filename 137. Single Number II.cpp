//version -1
//general way
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int bitnum[32]={0};  
        int res=0;  
        for(int i=0; i<32; i++)
        {  
            for(int j=0; j<nums.size(); j++)
            {  
                bitnum[i]+=(nums[j]>>i)&1;  
            }  
            res|=(bitnum[i]%3)<<i;  
        }  
        return res;  
    }
};

//version -2
//每次循环先计算 twos，即出现两次的 1 的分布，然后计算出现一次的 1 的分布
//接着 二者进行与操作得到出现三次的 1 的分布情况，然后对 threes 取反，再与 ones、twos进行与操作
//这样的目的是将出现了三次的位置清零。
class Solution {  
public:  
    int singleNumber(int A[], int n) {  
        int one=0, two=0, three=0;  
        for(int i=0; i<n; i++){  
            two |= one&A[i];  
            one^=A[i];  
            //cout<<one<<endl;  
            three=one&two;  
            one&= ~three;  
            two&= ~three;  
        }  
        return one;  
    }  
}; 