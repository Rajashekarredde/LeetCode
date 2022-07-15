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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector< vector<int> > ans;
        
        if ( root == NULL ) return ans ;
        
        queue<TreeNode*> store;
        store.push(root);
        
        vector< int> sub;
        sub.push_back( root->val );
        ans.push_back(sub);
        
        TreeNode *temp = new TreeNode();
        
        while( !store.empty() )
        {
            sub.clear();
            int n = store.size();
            for( int i =0; i<n; ++i )
            {                    
                temp = store.front();     
                store.pop();
                if( temp-> left != NULL )
                {
                    store.push( temp->left );
                    sub.push_back( (temp->left)->val );
                }

                if( temp->right != NULL)
                {
                    store.push( temp->right );
                    sub.push_back( (temp->right)->val );
                }                
            }
            if( sub.size() )
            ans.push_back( sub );
        }
        return ans;
    }
};