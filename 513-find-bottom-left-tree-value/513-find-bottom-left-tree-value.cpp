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
    int findBottomLeftValue(TreeNode* root) 
    {   
         std::queue< TreeNode* > q;
         q.push( root );
         int n, l;
         TreeNode* temp;
         while( !q.empty() )
         {
             n = q.size();
             for( int i =0; i<n; ++i )
             {
                 temp = q.front();
                 q.pop();
                 if( i == 0 )
                     l = temp->val;
                 if( temp->left ) q.push( temp->left );
                 if( temp->right ) q.push( temp->right );
             }
         }
         return l;
    }
};