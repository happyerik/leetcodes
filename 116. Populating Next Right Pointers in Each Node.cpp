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
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        queue<TreeLinkNode*> qt;
        qt.push(root);
        TreeLinkNode *prev = NULL, *cur;
        while (!qt.empty())
        {
            int ls = qt.size();
            prev = NULL;
            for (int i = 0; i < ls; i++)
            {
                cur = qt.front();
                qt.pop();
                
                if (prev != NULL)
                    prev->next = cur;
                prev = cur;
                
                if (cur->left != NULL)
                    qt.push(cur->left);
                if (cur->right != NULL)
                    qt.push(cur->right);
            }
            prev->next = NULL;
        }
    }
};