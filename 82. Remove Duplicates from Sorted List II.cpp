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
        ListNode *prev = head, *cur = head->next, *res;
        int nodecount = 0, flag = 0;
        while (cur != NULL)
        {
            if (cur->val != prev->val)
            {
                if (flag == 0)
                {
                    if (nodecount == 0)
                    {
                        res = prev;
                        head = prev;
                    }
                    else
                    {
                        res->next = prev;
                        res = res->next;
                    }
                    
                    nodecount++;
                    prev = cur;
                }
                else
                {
                    flag = 0;
                    prev = cur;
                }
            }
            else
                flag = 1;
                
            cur = cur->next;
        }
        
        if (nodecount == 0)
        {
            if (flag == 0)
                head = prev;
            else
                head = NULL; 
        }
        else
        {
            if (flag == 0)
            {
                res->next = prev;
                res->next->next = NULL;
            }
            else
                res->next = NULL; 
        }
            
        return head;
    }
};

//from Internet
ListNode *deleteDuplicates(ListNode *head) 
{  
    if(head == NULL || head->next == NULL)
	{  
        return head;  
    }  
    ListNode *p = new ListNode(-1);  
    p->next = head;  
    ListNode *cur = p, *pre = head;  
    while(pre != NULL)
	{  
        bool isDupli = false;  
        while(pre->next != NULL && pre->val == pre->next->val)
		{  
            isDupli = true;  
            pre = pre->next;  
        }  
        if(isDupli){  
            pre = pre->next;  
            continue;  
           
        }  
        cur->next = pre;  
        cur = cur->next;  
        pre = pre->next;  
          
    }  
    cur->next = pre;  
    return p->next;  
}  