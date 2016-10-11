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
    vector<int> rightSideView(TreeNode* root) 
    {
        if (root == NULL)
            return res;
        queue<TreeNode*> qt;
        qt.push(root);
        while (!qt.empty())
        {
            int sz = qt.size();
            TreeNode* tmp;
            for (int i = 0; i < sz; i++)
            {
                tmp = qt.front();
                qt.pop();
                if (tmp->left != NULL)
                    qt.push(tmp->left);
                if (tmp->right != NULL)
                    qt.push(tmp->right);
            }
            res.push_back(tmp->val);
        }
        return res;
    }
    vector<int> res;
};