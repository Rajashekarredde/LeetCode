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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = inorder.size();
        int preOrderIndex = 0;
        unordered_map< int, int > store;
        
        for( int i = 0; i<n; ++i )
            store[ inorder[i] ] = i;    
        
        TreeNode *ans = solve( inorder, preorder, preOrderIndex, 0, n-1, n, store );   
        return ans;
    }
    
    TreeNode * solve( vector<int> inorder, vector<int> preorder, int &index, int inorderStart, 
                      int inorderEnd, int n, unordered_map<int, int>&store  )
    {
        if( index >= n || inorderStart > inorderEnd )
            return nullptr;
        
        int element = preorder[ index++ ];
        TreeNode *root = new TreeNode( element );
        int position = store[element];
        root->left = solve( inorder, preorder,index, inorderStart, position - 1, n, store );
        root->right = solve( inorder, preorder, index, position + 1, inorderEnd, n, store );
        return root;
    }
};