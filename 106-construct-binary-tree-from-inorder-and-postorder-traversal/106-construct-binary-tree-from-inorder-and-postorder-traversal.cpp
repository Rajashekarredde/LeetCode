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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map< int, int > store;
        int n = inorder.size();
        for( int i =0; i<n ; ++i )
            store[ inorder[i] ] = i;
        int postorderIndex = n - 1;
        TreeNode *ans = solve( inorder, postorder, postorderIndex, 0, n-1, store );
        return ans;
    }
    
    TreeNode *solve( vector<int> inorder, vector<int> postorder, int &index, int inorderStart, 
                     int inorderEnd, unordered_map< int, int >&store )
    {
        if( index < 0 || inorderStart > inorderEnd )
            return nullptr;
        
        int element = postorder[index--];
        int position = store[element];
        TreeNode *root = new TreeNode(element);
        root->right = solve( inorder, postorder, index, position + 1, inorderEnd, store);
        root->left = solve( inorder, postorder, index, inorderStart, position - 1, store );
    
        return root;
    }
};