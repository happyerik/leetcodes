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

    //merge sort
    ListNode* sortList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode* head1 = head;
        ListNode* head2 = getMid(head);
        head1 = sortList(head1);
        head2 = sortList(head2);
        return merge(head1, head2);
    }
    
    //get the middle of the list
    ListNode* getMid(ListNode* head)
    {
        //guaranteed that at least two nodes
        ListNode* fast = head->next;
        ListNode* slow = head->next;
        ListNode* prev = head;
        while(true)
        {
            if(fast != NULL)
                fast = fast->next;
            else
                break;
            if(fast != NULL)
                fast = fast->next;
            else
                break;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;  // cut
        return slow;
    }

    //merge two list
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* newhead = new ListNode(-1);
        ListNode* newtail = newhead;
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->val <= head2->val)
            {
                newtail->next = head1;
                head1 = head1->next;
            }
            else
            {
                newtail->next = head2;
                head2 = head2->next;
            }
            newtail = newtail->next;
            newtail->next = NULL;
        }
        if(head1 != NULL)
            newtail->next = head1;
        if(head2 != NULL)
            newtail->next = head2;
        return newhead->next;
    }
};