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
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;
    int last;
    void recoverTree(TreeNode* root) 
    {
        first = NULL;
        second = NULL;
        prev = NULL;
        last = INT_MIN;
        inorder(root);
        swap(first->val, second->val);
    }
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        inorder(root->left);
        if(root->val < last)
        {
            if(first == NULL)
                first = prev;
            second = root;
        }
        prev = root;
        last = root->val;
        inorder(root->right);
    }
};