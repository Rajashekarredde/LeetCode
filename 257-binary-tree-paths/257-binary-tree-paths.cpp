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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;
        vector< int > st;
        solve( root, ans, st );
        return ans;
    }
    
    void solve( TreeNode *root, vector<string> &ans, vector<int> &st )
    {
        if( !root )
            return;
        
        st.push_back( root->val );
        solve( root->left, ans, st );
        solve( root->right, ans, st );
        
        if( !root->left  && !root->right )
        {   
            string str = "";
            for( int i = 0; i<st.size(); ++i )
            {
                str.append( to_string(st[i]) );
                if( i < st.size() - 1 )
                    str.append("->");
            }
            ans.push_back( str );
        }
        st.pop_back();
    }
};