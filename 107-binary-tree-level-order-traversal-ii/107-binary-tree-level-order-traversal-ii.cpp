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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector< vector<int> > ans;
        if( root == nullptr ) return ans;
        std::queue<TreeNode *> q;
        q.push( root );
        struct TreeNode* temp = new TreeNode();
        int n = 0;
        vector< int > sub;
        
        while( !q.empty() )
        {
            n = q.size();
            sub.clear();
            
            for( int i =0; i<n; ++i )
            {
               temp = q.front();
               q.pop();
               sub.push_back(temp->val);
               if( temp->left ) q.push( temp->left);
               if( temp->right ) q.push( temp->right );
            }
            
            ans.push_back( sub );
        }
        reverse( ans.begin(), ans.end() );
        return ans;
    }
};