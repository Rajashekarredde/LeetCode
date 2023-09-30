//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    
    struct Node* reverse(Node *head)
    {
        Node *revHead = nullptr;
        Node *temp = head;
        while( head )
        {
            head = head->next;
            temp->next = revHead;
            revHead = temp;
            temp = head;
        }
        return revHead;
    }
    
    void insert( Node * &ansHead, Node *&ansTail, int val )
    {
        Node *node = new Node(val);
        if( ansHead == nullptr )
        {
            ansHead = node;
            ansTail = node;
        }
        else
        {
            ansTail->next = node;
            ansTail = node;
        }
    }
    
    struct Node *add( Node *first, Node *second)
    {
        int digit = 0;
        int carry = 0;
        int sum = 0;
        Node *ansHead = nullptr;
        Node *ansTail = nullptr;
        
        while( first != nullptr || second != nullptr || carry != 0 )
        {
            int val1 = 0;
            if( first )
            {
                val1 = first->data;
                first = first->next;
            }
            
            int val2 = 0;
            if( second )
            {
                val2 = second->data;
                second = second->next;
            }
            
            int sum = val1 + val2 + carry;
            digit = sum % 10;
            carry = sum/10;
            
            insert( ansHead, ansTail, digit );
        }
        return ansHead;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        Node *ans = add(first, second);
        ans = reverse(ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends