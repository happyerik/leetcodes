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
    bool hasCycle(ListNode *head) 
    {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *slow = head, *fast = head->next->next;
        while (fast != NULL)
        {
            if (fast == slow)
                return true;
            slow = slow->next;
            if (fast->next == NULL)
                break;
            fast = fast->next->next;
        }
        return false;
    }
};