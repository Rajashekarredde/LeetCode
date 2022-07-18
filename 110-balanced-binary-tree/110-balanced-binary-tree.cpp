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
    bool isBalanced(TreeNode* root) 
    {
        int height = traversal ( root );
        if( height == -1) return false;
        return true;
    }
    
    int traversal( TreeNode *root )
    {
        if ( !root ) return 0;
        
        int l = traversal( root->left );
        if( l == -1 ) return -1;
        int r = traversal( root-> right );
        if ( r == -1 ) return -1;
        
        if( abs( l - r) > 1) return -1;
        
        return 1+ max( l,r);
    }
};