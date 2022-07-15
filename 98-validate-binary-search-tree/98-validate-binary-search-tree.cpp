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
    bool isValidBST(TreeNode* root) 
    {
        vector<int> ans;
        traversal( root, ans );
        int n = ans.size();
        
        for( int i =0; i< ( n-1) ; ++i )
        {
            if( ans[i] >= ans[i+1] )
                return false;
        }
        return true;
    }
    
    void traversal( TreeNode *root, vector<int> &ans )
    {
         if( root == NULL ) return ;
         traversal( root->left, ans);
         ans.push_back(root->val);
         traversal( root->right, ans);
    }
};