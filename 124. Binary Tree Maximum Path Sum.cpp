//version -1 TLE
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void maxSumRoot(TreeNode* root, int curSum, int& maxSum)
    {
        if (root == NULL)
        {
            //maxSum = max(curSum, maxSum);
            return;
        }
        curSum += root->val;
        maxSum = max(curSum, maxSum);
        maxSumRoot(root->left, curSum, maxSum);
        maxSumRoot(root->right, curSum, maxSum);
    }
    
    int submaxPathSum(TreeNode* root)
    {
        if (root == NULL)
            return INT_MIN;
        int curSum = 0, ml = 0, mr = 0;
        maxSumRoot(root->left, 0, ml);
        maxSumRoot(root->right, 0, mr);
        
        int cand1 = root->val + ml + mr;
        int cand2 = submaxPathSum(root->left);
        int cand3 = submaxPathSum(root->right);
        
        return max(max(cand1, cand2), cand3);
    }
    
    int maxPathSum(TreeNode* root) 
    {
        return submaxPathSum(root);
    }
};

//version -2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;
    int Helper(TreeNode *root) 
    {
        if(!root)
            return INT_MIN;
        else
        {
            int left = Helper(root->left);
            int right = Helper(root->right);
            if(root->val >= 0)
            {//allways include root
                if(left >= 0 && right >= 0)
                    maxSum = max(maxSum, root->val+left+right);
                else if(left >= 0 && right < 0)
                    maxSum = max(maxSum, root->val+left);
                else if(left < 0 && right >= 0)
                    maxSum = max(maxSum, root->val+right);
                else
                    maxSum = max(maxSum, root->val);
            }
            else
            {
                if(left >= 0 && right >= 0)
                    maxSum = max(maxSum, max(root->val+left+right, max(left, right)));
                else if(left >= 0 && right < 0)
                    maxSum = max(maxSum, left);
                else if(left < 0 && right >= 0)
                    maxSum = max(maxSum, right);
                else
                    maxSum = max(maxSum, max(root->val, max(left, right)));
            }
            //return only one path, do not add left and right at the same time
            return max(root->val+max(0, left), root->val+max(0, right));
        }
    }
    
    int maxPathSum(TreeNode* root) 
    {
        Helper(root);
        return maxSum;
    }
};

//version -3
/** 
 * Definition for a binary tree node. 
 * struct TreeNode { 
 *     int val; 
 *     TreeNode *left; 
 *     TreeNode *right; 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
 * }; 
 */  
  
class Solution {  
public:  
    int maxVal = INT_MIN;  
    int maxPathSum(TreeNode* root) {  
        if (root == NULL)  
            return 0;  
  
        maxSum(root);  
        return maxVal;  
    }  
  
    /*递归函数*/  
    int maxSum(TreeNode *root)  
    {  
        if (root == NULL)  
            return 0;  
  
        /*求以root为根的当前子树的最大路径和*/  
        int curVal = root->val;  
        int lmaxSum = maxSum(root->left), rmaxSum = maxSum(root->right);  
        if (lmaxSum > 0)  
            curVal += lmaxSum;  
        if (rmaxSum > 0)  
            curVal += rmaxSum;  
  
        if (curVal > maxVal)  
            maxVal = curVal;  
  
        /*返回以当前root为根的子树的最大路径和*/  
        return max(root->val, max(root->val + lmaxSum, root->val + rmaxSum));  
    }  
};  