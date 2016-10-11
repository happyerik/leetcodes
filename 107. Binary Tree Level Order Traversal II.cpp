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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode*> qt;
        qt.push(root);
        while (qt.size() > 0)
        {
            int tmp_size = qt.size();
            vector<int> tmp_vec(tmp_size, 0);
            for (int i = 0; i < tmp_size; i++)
            {
                TreeNode* tmp_ptr = qt.front();
                qt.pop();
                
                tmp_vec[i] = tmp_ptr->val;
                
                if (tmp_ptr->left != NULL)
                    qt.push(tmp_ptr->left);
                    
                if (tmp_ptr->right != NULL)
                    qt.push(tmp_ptr->right);
            }
            res.push_back(tmp_vec);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


//递归做法
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int> > result;

    void levelTra(TreeNode *root, int level)
    {
        if(root == NULL)
            return;
        if(level == result.size())
        {
            vector<int> v;
            result.push_back(v);
        }
        result[level].push_back(root->val);
        levelTra(root->left, level+1);
        levelTra(root->right, level+1);
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root) 
    {
        levelTra(root, 0);
        return vector<vector<int> >(result.rbegin(), result.rend());
    }
};