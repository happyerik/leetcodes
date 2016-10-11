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
    ListNode *detectCycle(ListNode *head) 
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        
        //judge if the list is a cycle
        ListNode *slow = head->next, *fast = head->next->next;
        while (fast != NULL)
        {
            if (slow == fast)
                break;
            if (fast->next == NULL || fast->next->next == NULL)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast == NULL)
            return NULL;
        
        //reset the slow pointer to the head and continue
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};