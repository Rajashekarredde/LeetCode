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
    int sumNumbers(TreeNode* root)
    {
        vector< int > path;
        int count = 0;
        solve( root, path, count );
        return count;
    }
    
    void solve( TreeNode *root, vector<int>path, int &count )
    {
        if( root == nullptr ) return;
        path.push_back( root->val );
        solve( root->left, path, count );
        solve( root->right, path, count );
            
        if( !root->left && !root->right )
        {
            long mul = 1;
            int n = path.size();
            for( int i = n-1; i>=0; i-- )
            {
                count += path[i] * mul;
                mul = mul *10;
            }
        }
        path.pop_back();
    }
};