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
class NodeValue
{
    public:
    int maxVal ;
    int minVal;
    bool isValid;
    int sum;
};

NodeValue solve( TreeNode *root, int &sum )
{
    if( !root )
        return {INT_MIN, INT_MAX, true,  0 };
    
    auto left = solve( root->left, sum );
    auto right = solve( root->right, sum );
    
    NodeValue cur;
    cur.maxVal = max( root->val, right.maxVal );
    cur.minVal = min( root->val, left.minVal );
    cur.sum = left.sum + right.sum+ root->val;
    cur.isValid = false;
    
    if( left.isValid && right.isValid && ( left.maxVal < root->val && root->val < right.minVal ) )
    {
        cur.isValid = true;
    }
    
    if( cur.isValid )
    {
        sum = max( sum, cur.sum);
    }
    return cur;
}

class Solution {
public:
    
    int maxSumBST(TreeNode* root) 
    {
        int sum = 0;
        NodeValue temp= solve( root, sum );
        return sum;
    }
};