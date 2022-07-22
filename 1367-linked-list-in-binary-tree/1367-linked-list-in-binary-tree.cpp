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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        bool ans = false;
        vector< int > path;
        vector<int> store;
        int i=0;
        
        while( head )
        {
            store.push_back( head->val);
            head = head->next;
        }
        solve( store, root, ans, path );
        return ans ;
    }
    
    void solve( vector<int> store, TreeNode *root, bool &ans, vector<int> path )
    {
        if( !root ) return;
        path.push_back(root->val);
        
        solve( store,root->left, ans, path);
        solve( store,root->right, ans, path);
        
        int n = path.size();
        int count = store.size() - 1;
        
        for( int i = n - 1; i >= 0; i-- )
        {            
            if( count >= 0 && path[i] == store[count] )
            {
                int k = i;
                
                for( int j = count; j >= 0; j-- )
                {
                    if( k<0 || store[j] != path[k--] )
                        break;
                    if( j == 0 ) ans= true;
                }
            }
        }
        
        path.pop_back();
    }
};