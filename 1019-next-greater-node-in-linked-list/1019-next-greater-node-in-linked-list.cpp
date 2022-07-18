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
    vector<int> nextLargerNodes(ListNode* head) 
    {
        ListNode *temp =head, *temp_a=NULL;
        vector<int> ans;
        while( temp->next )
        {
            temp_a = temp->next;
            if( temp_a )
            {
                while( temp_a && ( temp->val >= temp_a->val) )
                    temp_a = temp_a->next;
                  
                if( !temp_a )
                    ans.push_back(0);
                else
                    ans.push_back( temp_a->val);
            }
            temp = temp->next;
        }
        ans.push_back(0);
        return ans;
    }
};