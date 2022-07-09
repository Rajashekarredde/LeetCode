/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        struct ListNode *dummy = new ListNode();
        dummy->val = INT_MIN;
        dummy->next = head;
        head = dummy;
        
        struct ListNode *p = head;
        struct ListNode *q = head->next;
        
        while( q )
        {
            if( q->val == val )
            {
                p->next = q->next;
            }
            else
                p = p->next;
            
            q= q->next;
        }
        return dummy->next;
    }
};