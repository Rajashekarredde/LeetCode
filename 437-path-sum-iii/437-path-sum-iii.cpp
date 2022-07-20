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
    int pathSum(TreeNode* root, int k ) 
    {
        vector<int> path;
        long count = 0;
        solve( root, count, k, path );
        return count;
    }
    
    void solve( TreeNode *root, long &count, int k, vector<int>path )
    {
        if( root == NULL )
            return ;
        path.push_back(root->val);
        
        solve( root->left, count, k, path );
        solve( root->right, count, k, path );
        
        long n = path.size();
        long sum = 0;
        for( int i = n-1; i>=0; i-- )
        {
            sum+= path[i];
            if( k == sum )
                count++;
        }
        path.pop_back();
    }
};