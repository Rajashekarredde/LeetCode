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
    vector<int> largestValues(TreeNode* root) 
    {
         vector< int > ans;
        if( root == nullptr )
            return ans;
        
         std::queue< TreeNode* > q;
         q.push( root );
         int n , max=0;
         struct TreeNode *temp;
         
        while( !q.empty() )
        {
            n = q.size();
            max=INT_MIN;
            for( int i =0; i<n; ++i )
            {
                temp = q.front();
                q.pop();
                if( max < temp->val )
                    max = temp->val;
                if( temp->left) 
                    q.push( temp->left );
                if( temp->right )
                    q.push(temp-> right);
            }
            ans.push_back( max );
        }
        return ans;
    }
};