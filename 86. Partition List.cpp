/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = NULL, *right = NULL, *cur = head, *res1 = NULL, *res2 = NULL;
        while (cur != NULL)
        {
            if (cur->val < x)
            {
                if (left == NULL)
                {
                    left = cur;
                    res1 = cur;
                }
                else
                {
                    left->next = cur;
                    left = left->next;
                }
            }
            else
            {
                if (right == NULL)
                {
                    right = cur;
                    res2 = cur;
                }
                else
                {
                    right->next = cur;
                    right = right->next;
                }
            }
            cur = cur->next;
        }
        if (left == NULL || right == NULL)
            return head;
        else
        {
            right->next = NULL;
            left->next = res2;
            return res1;
        }
    }
};