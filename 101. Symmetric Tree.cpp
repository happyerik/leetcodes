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
    bool helper(TreeNode* l, TreeNode* r)
    {
        if (l == NULL && r == NULL)
            return true;
        else if ((l != NULL && r == NULL) || (l == NULL && r != NULL))
            return false;
        else
            return (l->val == r->val) && helper(l->left, r->right) && helper(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        if (root == NULL)
            return true;
        else
        {
            return helper(root->left, root->right);
        }
    }
};


//verison -2
bool isSymmetric(TreeNode* root) 
    {
        if (root == NULL)
            return true;
        else
        {
            deque<TreeNode*> dt;
            dt.push_back(root);
            while (dt.size() != 0)
            {
                int tmp_size = dt.size();
                vector<int> tv;
                for (int i = 0; i < tmp_size; i++)
                {
                    TreeNode* tmp = dt.front();
                    dt.pop_front();
                    if (tmp->left != NULL)
                    {
                        dt.push_back(tmp->left);
                        tv.push_back(tmp->left->val);
                    }
                    else
                        tv.push_back(0);
                        
                    if (tmp->right != NULL)
                    {
                        dt.push_back(tmp->right);  
                        tv.push_back(tmp->right->val);
                    }
                    else
                        tv.push_back(0);
                }
                for (int i = 0; i < tv.size() / 2; i++)
                {
                    if (tv[i] != tv[tv.size() - 1 - i])
                        return false;
                }
            }
            return true;
        }
    }