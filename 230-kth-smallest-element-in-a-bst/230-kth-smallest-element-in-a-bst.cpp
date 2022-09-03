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

class bst
{
    public:
    stack<TreeNode*> st;
    bst( TreeNode *root )
    {
        pushAll( root );
    }
    
    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushAll( temp->right );
        return temp->val;
    }
    
    void pushAll( TreeNode *node )
    {
        while( node )
        {
            st.push( node );
            node = node->left;
        }
    }
};

class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) 
    {
        bst l(root);
        int ele = 0;
        while( k-- )
        {
            ele = l.next();
        }
        return ele;
    }
};