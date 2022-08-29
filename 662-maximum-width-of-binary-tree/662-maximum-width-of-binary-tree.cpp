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
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue< pair<TreeNode*, int> > q;
        q.push( {root, 0} );
        long ans = 0;
        while( !q.empty() )
        {
            long n = q.size();
            long last = q.back().second;
            long first = q.front().second;
            
            ans = max( ans, (last - first)+1 );
            for( int i = 0; i<n; ++i )
            {
                TreeNode *node = q.front().first;
                long level = q.front().second;
                q.pop();
                if( node->left )
                    q.push( {node->left, (2*level+1) });
                 if( node->right )
                    q.push( {node->right, (2*level+2) });
            }
        }
        return ans;
    }
};