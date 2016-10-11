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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *res = head, *prev = head, *cur = prev->next;
        while (cur != NULL)
        {
            if (cur->val == prev->val)
            {
               //prev->next = cur->next;
               prev = cur;
            }
            else
            {
                res->next = cur;
                res = res->next;
                prev = cur;
            }
            cur = cur->next;
        }
        res->next = NULL;
        return head;
    }
};