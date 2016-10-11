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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* helper = new ListNode(-1);
        helper->next = head;
        ListNode* prev = helper, *cur = head, *next;
        while (cur != NULL)
        {
            next = cur->next;
            if (cur->val == val)
                prev->next = next;
            else
                prev = cur;
            cur = next;
        }
        return helper->next;
    }
};