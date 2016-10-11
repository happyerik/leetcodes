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
    vector<vector<int>> res;
    
    void helper(TreeNode* root, int sum, vector<int> part_res)
    {
        if (root == NULL)
            return;
        else
        {
            part_res.push_back(root->val);
            if (root->left != NULL || root->right != NULL)
            {
                helper(root->left, sum - root->val, part_res);
                helper(root->right, sum - root->val, part_res);
            }
            else
            {
                if (root->val == sum)
                    res.push_back(part_res);
                else
                    return;
            }
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<int> part_res;
        helper(root, sum, part_res);
        return res;
    }
};