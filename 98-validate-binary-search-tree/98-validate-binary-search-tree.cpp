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
class info
{
    public: 
    long long int maxi;
    long long int  mini;
    bool isValid;
};

info solve( TreeNode *root )
{
    if( !root )
        return {LONG_MIN, LONG_MAX, true };
    
    auto left = solve( root->left);
    auto right = solve( root->right );
    
    info cur;
    cur.maxi = max<long long int>( right.maxi, root->val );
    cur.mini = min<long long int>( left.mini, root->val );
    cur.isValid = false;
    
    if( left.isValid && right.isValid && ( left.maxi < root->val && root->val < right.mini ) )
    {
        cur.isValid= true;
    }
    return cur;
}

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {   
        if( !root )
            return true;
        return solve( root).isValid;
    }  
};