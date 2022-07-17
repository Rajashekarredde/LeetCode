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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        root = insert( root, val );
        return root;
    }
    
    TreeNode* insert( TreeNode *root, int data )
    {
        if( root == nullptr )
            root = create(data);
        else if ( data <= root->val )
            root->left = insert( root->left, data );
        else 
            root->right = insert( root->right, data );
        return root;
    }
    
    TreeNode *create( int data )
    {
        TreeNode *newNode = new TreeNode();
        newNode->val = data ;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
};