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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *dummy = new ListNode();
        dummy->val = 0;
        dummy->next = head;
        head = dummy;
        
        ListNode *left = head;
        ListNode *right = head->next;


        while( n > 0 && right )
        {
            right = right->next;
            n--;
        }
        
        while( right )
        {
            left = left->next;
            right = right->next;
        }
        
        cout<<left->val;
        left->next = left->next->next;
        
        return dummy->next;
    }
};