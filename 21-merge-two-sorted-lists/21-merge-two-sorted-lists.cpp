
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if( !list1 ) return list2;
        if( !list2 ) return list1;
        
        ListNode* new_node = nullptr;
        ListNode* sorting = nullptr;
        
        if( list1 && list2 )
        {
            if( list1->val <= list2->val )
            {
                sorting = list1;
                list1= list1->next;
            }
            else
            {
                sorting = list2;
                list2= list2->next;
            }
            new_node = sorting;
        }
        
        while( list1 && list2 )
        {
            if( list1->val <= list2->val )
            {
                sorting->next= list1;
                sorting = list1;
                list1 = list1->next;
            }
            else
            {
                sorting->next = list2;
                sorting = list2;
                list2 = list2->next;
            }
        }
        
        if( list1 == nullptr ) sorting->next = list2;
        if( list2 == nullptr ) sorting->next = list1;
        return new_node;
    }
};