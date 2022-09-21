/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if( !root )
            return "";
        
        queue<TreeNode*> q;
        q.push( root );
        
        string s = "";
        while( !q.empty() )
        {
            TreeNode *temp = q.front();
            q.pop();
            if( temp )
                s.append(to_string(temp->val)+",");
            else
                s.append("#,");
            if( temp )
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if( data == "" )
            return nullptr;
        
        stringstream s(data);
        string str;
        
        getline( s, str, ',' );
        
        TreeNode *root = new TreeNode(stoi(str) );
        queue<TreeNode*> q;
        q.push( root );
        
        while( !q.empty() )
        {
            TreeNode *temp = q.front();
            q.pop();
            
            getline( s, str, ',' );
            if( str != "#" )
            {
                TreeNode *node = new TreeNode(stoi(str) );
                q.push( node );
                temp->left  = node;
            }
            else
                temp->left  = nullptr;
            
            getline( s, str, ',' );
            if( str != "#" )
            {
                TreeNode *node = new TreeNode(stoi(str) );
                q.push(node);
                temp->right  = node;
            }
            else
                temp->right  = nullptr;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));