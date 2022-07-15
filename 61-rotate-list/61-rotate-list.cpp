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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if( !head ) return nullptr;
        int count = 0;
        ListNode *temp = head;
        while( temp->next != NULL )
        {
            count ++;
            temp = temp->next;
        }
        if( !count  || ( count == k-1 ))
            return head;
        
        count++;
        temp->next = head;
        
        if( k > count )
            k = ( k % count);
        
        k = (count - k) - 1;
        temp = head;
        while( k -- )
        {
            temp=temp->next;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }   
};