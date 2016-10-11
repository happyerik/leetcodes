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
    TreeNode* helper(vector<int>& preorder, int pi, int pj, vector<int>& inorder, int ii, int ij)
    {
        int ps = preorder.size();
        int is = inorder.size();
        if (pi >= pj || ii >= ij || pi >= ps || ii >= is)
            return NULL;
        int rv = preorder[pi];
        int ir = ii;
        for (; ir < ij; ir++)
        {
            if (inorder[ir] == rv)
                break;
        }
        TreeNode* tmp_ptr = new TreeNode(rv);
        tmp_ptr->left = helper(preorder, pi+1, pi+1+(ir-ii), inorder, ii, ir);
        tmp_ptr->right = helper(preorder, pi+1+(ir-ii), pj, inorder, ir+1, ij);
        return tmp_ptr;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int ps = preorder.size();
        int is = inorder.size();
        return helper(preorder, 0, ps, inorder, 0, is);
    }
};