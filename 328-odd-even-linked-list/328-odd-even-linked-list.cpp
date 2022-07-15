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
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode *evenStart = new ListNode();
        evenStart->val = 0;
        evenStart->next = nullptr;
        
        ListNode *oddStart = new ListNode();
        oddStart->val = 0;
        oddStart->next = nullptr;
        
        ListNode *evenEnd = evenStart, *oddEnd = oddStart ;
        
        int i = 1;
        
        while( head )
        {
            if( i%2 == 0 )
            {
                evenEnd->next = head;
                head = head->next;
                evenEnd = evenEnd->next;
                evenEnd->next = nullptr;
            }
            else
            {
                oddEnd->next = head;
                head = head->next;
                oddEnd = oddEnd->next;
                oddEnd->next = nullptr;
            }
            i++;
        }
        evenStart = evenStart->next;
        oddStart  = oddStart->next;
        oddEnd->next = evenStart;
        
        return oddStart;
    }
};