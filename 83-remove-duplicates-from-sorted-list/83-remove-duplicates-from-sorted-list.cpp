
class Solution 
{
    public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
       if( !head )
           return head;
        
       struct ListNode *p = head;
       struct ListNode *q = head->next;
        
       while( q )
       {
           if( p->val == q-> val )
               p->next = q->next;
           else
               p = p->next;
           q= q->next;
       }
        return head;
    }
};