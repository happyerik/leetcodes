/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) 
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }    
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        if (st.empty())
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() 
    {
        TreeNode *tmp1 = st.top(), *tmp2;
        st.pop();
        
        tmp2 = tmp1->right;
        while (tmp2 != NULL)
        {
            st.push(tmp2);
            tmp2 = tmp2->left;
        }
        return tmp1->val;
    }
    
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */