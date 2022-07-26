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
    vector<vector<int>> pathSum(TreeNode* root, int k) 
    {
           
        vector<int> path;
        vector< vector<int> >ans;
        
        if(!root)
            return ans;
        
        solve(path, root, k, ans);
        
        return ans;
    }
    
    void solve( vector<int>&path, TreeNode *root, int k, vector< vector<int> >&ans )
    {
        if( root == NULL ) return;
        
        path.push_back( root->val );
        
        if( !root->left && !root->right && k == root->val)
            ans.push_back( path );
        
        solve( path, root->left, k-root->val, ans );
        solve( path, root->right, k-root->val, ans );
        
        path.pop_back();
    }
};