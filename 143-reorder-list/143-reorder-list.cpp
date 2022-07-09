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
    void reorderList(ListNode* head) 
    {
         ListNode *slow = head;
         ListNode *fast = head->next;
         while( fast && fast->next )
         {
             slow = slow->next;
             fast = fast->next->next;
         }
        
         ListNode *second = slow->next;
         ListNode *prev = nullptr;
         slow->next = nullptr;
         while( second )
         {
             ListNode *temp = second;
             second = second->next;
             temp->next=prev;
             prev=temp;
         }       
          
         ListNode *p = head;
         ListNode *q = prev;
         ListNode *temp1, *temp2;
         
         while( q )
         {
             temp1 = p->next;
             temp2 = q->next;
             p->next = q;
             q->next = temp1;
             p = temp1;
             q = temp2;
         }
    }
};