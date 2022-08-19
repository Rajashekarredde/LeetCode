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
    ListNode* reverseList(ListNode* head) 
    {
         struct ListNode *new_node = nullptr ;
         
         while( head != nullptr )
         {
             struct ListNode *temp = head->next;
             head->next = new_node;
             new_node = head;
             head = temp;
         }
        return new_node;
    }
};