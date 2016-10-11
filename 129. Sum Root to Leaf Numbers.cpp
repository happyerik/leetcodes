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
    void helper(TreeNode* root, int num, int& res)
    {
        num = num * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            res += num;
            return;
        }
        if (root->left != NULL)
            helper(root->left, num, res);
        if (root->right != NULL)    
            helper(root->right, num, res);
    }
    
    int sumNumbers(TreeNode* root) 
    {
        int res = 0;
        if (root == NULL)
            return res;
        helper(root, 0, res);
        return res;
    }
};