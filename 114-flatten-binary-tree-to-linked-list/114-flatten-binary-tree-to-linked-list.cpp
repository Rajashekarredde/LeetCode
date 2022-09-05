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
    void flatten(TreeNode* root) 
    {
        if( !root )
            return ;
        
        TreeNode *temp = root;
        TreeNode *prev = nullptr;
        while( temp )
        {
            if( temp->left != nullptr )
            {
                prev = temp->left;
                while( prev ->right )
                    prev = prev->right;
                
                prev->right =temp->right;
                temp->right = temp->left;
                temp->left = nullptr;
            }
            temp = temp->right;
        }
      
    }
};