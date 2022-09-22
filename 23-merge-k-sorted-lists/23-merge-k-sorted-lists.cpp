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

class mycompare{
	public:
	bool operator()(const ListNode* a,const ListNode* b)
    {
        return (a->val > b->val);
    }
};


class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {   
        ListNode *dummyHead = new ListNode(0);
        ListNode *temp = dummyHead;
        
        priority_queue< ListNode*, vector<ListNode*>, mycompare > pq;
        
        for( int i = 0; i<lists.size(); ++i )
        {
            if( lists[i] != nullptr )
            pq.push( lists[i] );
        }
        
        while( !pq.empty() )
        {
            auto node = pq.top();
            pq.pop();
            
            temp->next = node;
            temp = temp->next;
            
            if( node->next )
                pq.push( node->next );
        }
            
        return dummyHead->next;
    }
};