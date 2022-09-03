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
    bool reverse = true;
    bst( TreeNode *root, bool isReverse )
    {
        reverse = isReverse;
        pushAll( root );
    }
    
    int next()
    {
        TreeNode *temp = st.top();
        
        st.pop();
        
        if( reverse )
            pushAll( temp->left  );
        else 
            pushAll( temp->right );
        return temp->val;
    }
    
    void pushAll( TreeNode *node )
    {
        while( node )
        {
            st.push( node );
            if( reverse )
                node = node->right;
            else
                node = node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) 
    {
        bst l( root, false);
        bst r( root, true );
        
        int i = l.next();
        int j= r.next();
        while( i < j )
        {
            if( i +j == k ) 
                return true;
            if( i + j < k )
                 i = l.next();
            else
                j = r.next();
        }
        return false;
    }
    
};