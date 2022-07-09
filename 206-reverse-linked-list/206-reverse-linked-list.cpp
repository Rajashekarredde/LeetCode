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
        struct ListNode *new_node = nullptr;
        while( head )
        {
            struct ListNode *temp = head;
            head = head->next;
            temp->next = new_node;
            new_node = temp;
        }
        return new_node;
    }
};