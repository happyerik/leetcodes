/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        if (root == nullptr)  
            return;  
          
        if (root->left != nullptr)  
            root->left->next = root->right;  
          
        TreeLinkNode* child = root->left;  
        if (root->right) child = root->right;  
          
        if (child != nullptr)  
        {  
            TreeLinkNode* i = root->next;  
            while( i != nullptr && i->left == nullptr && i->right == nullptr)  
                i = i->next;  
              
            if (i != nullptr)  
            {  
                if (i->left)  
                    child->next = i->left;  
                else  
                    child->next = i->right;  
            }  
        }  
          
        // This is critical since we need the right hand side  
        // next is ready before the left hand side  
        if (root->right) connect(root->right);  
        if (root->left) connect(root->left);  
    }
};