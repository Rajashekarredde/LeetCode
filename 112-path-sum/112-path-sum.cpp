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
    
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        int sum = 0;
        return isExist( root, sum , targetSum);
    }
    
    bool isExist( TreeNode* root, int sum, int target )
    {
         if( root == nullptr ) return false;
        
         sum+= root->val;
        
        if( !root->left && !root->right )
             return sum == target;
        
         return ( isExist(root->left, sum, target) || isExist(root->right, sum, target) );
    }
};