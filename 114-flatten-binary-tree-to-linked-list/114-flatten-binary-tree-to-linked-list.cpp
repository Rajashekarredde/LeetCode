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
        
        TreeNode *node = root;
        while( node )
        {
            if( node->left != nullptr )
            {
                TreeNode *temp = node->left;
                while( temp->right )
                    temp = temp->right;
                temp->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            
            node = node->right;
        }
    }
};