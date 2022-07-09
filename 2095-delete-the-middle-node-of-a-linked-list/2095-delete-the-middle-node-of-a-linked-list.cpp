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
    ListNode* deleteMiddle(ListNode* head) 
    {
       struct ListNode *dummy = new ListNode();
        dummy->val = 0;
        dummy->next = head;
        head = dummy;
        
        struct ListNode*p = head;
        struct ListNode*q = head->next;
        
        while( q && q->next )
        {
            p = p->next;
            q=q->next->next;
        }
        struct ListNode *del = p->next;
        p->next = p->next->next;
        delete( del );
        
        return dummy->next;
    }
};