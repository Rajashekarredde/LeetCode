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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector< vector<int> >ans;
        if( root == nullptr )
            return ans;
        queue<TreeNode*>q;
        q.push( root);
        bool rev = false;
        while( !q.empty() )
        {
            int n = q.size();
            vector<int> temp; 
            for( int i=0; i<n; ++i )
            {
                TreeNode  *node = q.front();
                temp.push_back( node->val );
                q.pop();
                if( node->left )
                    q.push( node->left );
                if( node->right )
                    q.push( node->right );
            }
            if( rev )
            {
                reverse( temp.begin(), temp.end() );
                rev = false;
            }
            else
            {
                rev= true;
            }
            ans.push_back( temp );
        }
        return ans;
    }
};